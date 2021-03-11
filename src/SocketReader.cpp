#include <unistd.h>
#include <stdexcept>
#include <regex>
#include <iostream>
#include <sys/socket.h>

#include "SocketReader.h"

namespace netOptix
{

    std::string SocketReader::readFromSocket(int connection) 
    {
        char buffer[1028];

        memset(buffer, 0x00, 1028);

        std::size_t incoming = recv(connection, buffer, 1028, 0);

        if (incoming < 0) 
        {
            throw std::runtime_error("FAILED reading from socket.");
        }

        std::string msg(buffer);
        std::cout << msg << std::endl;
        return msg;
    }

} // namespace netOptix
