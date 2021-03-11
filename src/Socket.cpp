#include <netdb.h>
#include <netinet/in.h>
#include <stdexcept>
#include <strings.h>
#include <cstring>
#include <unistd.h>

#include "Socket.h"

namespace netOptix
{

    Socket::Socket(int port) 
    {
        mSocketfd = ::socket(AF_INET, SOCK_STREAM, 0);
        if (mSocketfd < 0) 
        {
            throw std::runtime_error("FAILED socket creation.");
        }
        struct sockaddr_in addr{};
        bzero((char *) &addr, sizeof(addr));

        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        if (bind(mSocketfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) 
        {
            throw std::runtime_error("FAILED port binding " + std::to_string(port));
        }
    }

    Socket::~Socket() 
    {
        close(mSocketfd);
    }

    int Socket::wait() 
    {
        if (listen(mSocketfd, 20) < 0) 
        {
            throw std::runtime_error("FAILED listening.");
        }
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int updated_socketfd = accept(mSocketfd, reinterpret_cast<sockaddr*>(&client_addr), &client_len);
        if (updated_socketfd < 0) 
        {
            throw std::runtime_error("FAILED accepting input.");
        }
        return updated_socketfd;
    }

} // namespace netOptix
