#pragma once

#include <string>

namespace netOptix
{
    class Socket 
    {
    public:
        explicit Socket(int port);
        ~Socket();
        int wait();

    private:
        int mSocketfd;
    };
} // namespace netOptix
