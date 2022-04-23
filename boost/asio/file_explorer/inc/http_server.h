#ifndef HTTP_SERVER_H_
#define HTTP_SERVER_H_

#include <boost/asio.hpp>
#include <files.h>
#include <html.h>
#include <iostream>

class HTTP_Server {

  public:
    HTTP_Server(const std::string &host, const std::string &protocol) noexcept;
    void start();
    bool stop();

    boost::asio::const_buffer handleMsg(const std::string &request);

  private:
    boost::asio::io_context io;
    boost::asio::ip::tcp::acceptor acceptor;
};

#endif // HTTP_SERVER_H_
