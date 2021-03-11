#include <gtest/gtest.h>
#include "../src/ShaHasher.h"
//#include "../src/HashServer.h"

TEST(ShaHasher_1, CalculateHash)
{
    netOptix::ShaHasher shaHasher(1); // just one hash-iteration
    ASSERT_EQ("c775e7b757ede630cd0aa1113bd102661ab38829ca52a6422ab782862f268646", shaHasher.hash("1234567890"));
    ASSERT_EQ("bef57ec7f53a6d40beb640a780a639c83bc29ac8a9816f1fc6c5c6dcd93c4721", shaHasher.hash("abcdef"));
    ASSERT_EQ("cbc51a2865b00cf6934f2b8060dccca66db46be3461a2622f15077f03255db02", shaHasher.hash("Hey, Arnold!"));
}

TEST(ShaHasher_2, CalculateHashN)
{
    netOptix::ShaHasher shaHasher(2); // two hash-iterations
    ASSERT_EQ("e7515a26f405b2235d885588ab610c59429e02a0f8edda94fdc1f32697c797e4", shaHasher.hashN("1234567890"));
    ASSERT_EQ("1c3951fc51112a02ae7a82720fbed831a07bcde22bdaffefdea17392b6687620", shaHasher.hashN("abcdef"));
    ASSERT_EQ("a3ebed8fea457650c5d5d6d75d2fb7b06fb06090a95d68c06b4aa0f692bda86a", shaHasher.hashN("Hey, Arnold!"));
}

TEST(ShaHasher_Base, CalculateHash)
{
    netOptix::ShaHasher shaHasher(1);
    ASSERT_EQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", shaHasher.hash(""));
}

