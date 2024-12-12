#include "../include/read_from_cli.hpp"
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

char next();

bool check(char& c, const int& level);

int main(int argc, char* argv[]) {
  std::ifstream f = from_cli(argc, argv);

  std::string data, temp;
  while (getline(f, temp)) {
    data.append(temp);
  }
  // std::cerr << data;
  
  f.close();
  
}
