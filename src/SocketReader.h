#pragma once

#include <string>

namespace netOptix
{

    class SocketReader 
    {
    public:
        SocketReader() = default;
        ~SocketReader() = default;

        std::string readFromSocket(int connection);
    };

} // netOptix
