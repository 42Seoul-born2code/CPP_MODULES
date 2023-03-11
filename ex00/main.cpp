#include <iostream>
#include "Convertor.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: Wrong Argument" << std::endl;
    return (1);
  }
  std::string value = argv[1];

  Convertor convertor(value);
  convertor.convert();

  return 0;
}