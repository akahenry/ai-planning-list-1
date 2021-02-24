#include "parser.hpp"

int main(int argc, char** argv) 
{
    Program* prog = Parser::parse(argc, argv);

    std::cout << prog->algorithm;

    return 0;
}