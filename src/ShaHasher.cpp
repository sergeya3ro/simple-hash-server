#include "ShaHasher.h"

#include <utility>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <iostream>

namespace netOptix
{
    ShaHasher::ShaHasher(int rounds) 
    {
        mRounds = rounds;
    }

    std::string ShaHasher::hashN(const std::string &input) 
    {
        std::string out = input;
        for (int i = 0; i < mRounds; ++i) 
        {
            out = hash(out);
        }
        return out;
    }

    std::string ShaHasher::hash(const std::string &str) 
    {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (unsigned char i : hash) 
        {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)i;
        }
        return ss.str();
    }
} // namespace netOptix
