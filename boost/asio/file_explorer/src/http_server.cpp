#include "http_server.h"

HTTP_Server::HTTP_Server(const std::string &host, const std::string &protocol)
    : io{1}, acceptor{io} {

    try {
        boost::system::error_code ec;
        boost::asio::ip::tcp::resolver _resolvers{io};
        auto result = _resolvers.resolve(host, protocol);

        for (const auto &i : result) {
            std::cout << i.endpoint() << " hostname : " << i.host_name()
                      << "\n";
        }

        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(),
                                                stoi(protocol));
        acceptor.open(endpoint.protocol());

        acceptor.set_option(
            boost::asio::ip::tcp::acceptor::reuse_address(true));
        acceptor.bind(endpoint);
    } catch (boost::system::error_code &ec) {
        std::cerr << "error at init " << ec.what() << "\n";
        exit(-1);
    }
}

auto HTTP_Server::start() -> void {
    try {
        auto future = std::async(std::launch::async, [&]() {
            acceptor.listen();

            boost::system::error_code ec;
            boost::asio::ip::tcp::socket socket(io);
            acceptor.accept(socket);

            std::cout << "a new incomming request\n";

            std::string request;
            std::string data;
            boost::asio::read_until(
                socket, boost::asio::dynamic_buffer(request), '\n', ec);
#ifdef DEBUG
            std::cout << "request " << request << "\n";
#endif

            std::string var = std::move(handleMsg(request));
            auto length = var.length();
            boost::asio::const_buffer buf{std::move(var).data(), length};
            boost::asio::async_write(
                socket, buf,
                [](boost::system::error_code ec, size_t transferred) {
                    std::cout << "written size = " << transferred
                              << "\n ec = " << ec << "\n";
                });
        });
    } catch (boost::system::error_code &ec) {
        std::cout << "error " << ec.what() << "\n";
    }
    // prepare for another request
    start();
}
auto HTTP_Server::stop() -> bool { return true; }

auto HTTP_Server::handleMsg(const std::string &request)
    -> std::string {

    std::string response;
    response.clear();
    html req(request);

    auto method = req.get_requested_method();
    if (method == html::GET) {
        try {
            std::cout << "method " << method << "\n";
            auto req_path = req.get_requested_path();
            auto a = Files::read_path(req_path);
            std::stringstream ss;

            std::cout << req.get_requested_path() << " << requested path \n";
            fs::path parent_fs_path(req_path);
            fs::path parent_path("/");
            if (std::count(req_path.begin(), req_path.end(), '/') > 1) {
                parent_path = parent_fs_path.parent_path();
            }

            Files parent_a(parent_path.c_str());
            ss << "<h1> Parent Directory : " << parent_a << "</h1>\n";

            for (auto &i : a) {
                ss << i << "<br>\n";
            }

            ss = html::fill_header4http(ss.str());

            response = ss.str();
        } catch (std::exception &ex) {
            std::cout << "error : " << ex.what() << "\n";
            exit(0);
        }
    }

    return response;
}
