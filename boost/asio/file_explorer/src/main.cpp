#include "files.h"
#include "html.h"
#include "http_server.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
//#define DEBUG

using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

auto main(int argc, char *argv[]) -> int {
    // Check command line arguments.
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " ip protocol\n";
        return EXIT_FAILURE;
    }

    HTTP_Server http_server(argv[1], argv[2]);
    http_server.start();

    return 0;
}
