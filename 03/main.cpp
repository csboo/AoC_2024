#include "../include/read_from_cli.hpp"
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main(int argc, char* argv[]) {
  std::ifstream f = from_cli(argc, argv);

  std::string data, temp;
  while (getline(f, temp)) {
    data.append(temp);
  }
  // std::cerr << data;

  std::regex regex("mul\\(\\d{1,3},\\d{1,3}\\)");
  auto current_match = std::sregex_iterator(data.begin(), data.end(), regex);
  auto data_end = std::sregex_iterator();
 
    
  while (current_match != data_end) {

      std::smatch match = *current_match;
      int num1 = std::stoi(match[1].str());
      int num2 = std::stoi(match[2].str());
      std::cout << "First number: " << num1 << std::endl;
      std::cout << "Second number: " << num2 << std::endl;
      ++current_match;
  }
  f.close();
}
