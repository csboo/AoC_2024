#pragma once

#include <fstream>
#include <iostream>

inline std::ifstream from_cli(const int& argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "You must provide only 1 argument!\n";
    exit(1);
  }
  std::ifstream f(argv[1]);  
  if (!f.is_open()) {
    std::cerr << "Error while opening file: " << argv[1] << "\n";
    exit(1);
  }
  return f;
}
