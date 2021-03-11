#pragma once

#include <string>
#include "Hasher.h" 

namespace netOptix
{
    class ShaHasher : public Hasher 
    {
    public:
        ShaHasher() = default;
        explicit ShaHasher(int rounds);
        std::string hash(const std::string &in) override;
        std::string hashN(const std::string &in) override;

    private:
        int mRounds{1};
    };
} // namespace netOptix
