#include <memory>
#include <iostream>

#include "HashServer.h"
#include "ShaHasher.h"

using namespace netOptix;

int main() 
{
    int concurrent = 20;
    int port = 8080;
    std::cout << concurrent << std::endl;
    std::cout << port << std::endl;
    try
    {
        std::make_unique<HashServer>(
            concurrent,
            port,
            *std::make_unique<ShaHasher>()
        )->run();
    }
    catch (std::runtime_error e)
    {
	    std::cout << e.what() <<std::endl;
    }
}
