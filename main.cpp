//
// Created by Christopher Jaramillo on 2019-04-12.
//

#include <iostream>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[]){
    std::cout << "Hello World" << std::endl;
    boost::filesystem::path aPath = boost::filesystem::current_path();
    boost::filesystem::directory_iterator it(aPath);
    while(it != boost::filesystem::directory_iterator())
    {
        std::cout << *it++ << std::endl;
    }
    return EXIT_SUCCESS;
}