#pragma once

#include <string>

namespace netOptix
{
    class Hasher 
    {
    public:
        virtual ~Hasher()= default;
        virtual std::string hash(const std::string& input) = 0;
        virtual std::string hashN(const std::string& input) = 0;

    private:
        int mRounds;
    };
} // namespace netOptix
