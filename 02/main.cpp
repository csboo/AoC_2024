// DAY 2
#include "../include/read_from_cli.hpp"

#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

static bool is_safe(std::vector<int>& v, const bool& _is_already_dampened = false);

int main(int argc, char* argv[]) {
  std::ifstream f = from_cli(argc, argv);

  std::string line;
  int count = 0;
  while (std::getline(f, line)) {
    int num;
    std::istringstream iss(line);
    std::vector<int> line; // Probably not the most efficient, but it works well, still TODO
      while (iss >> num) {
      line.push_back(num);
    }

    if (is_safe(line)) count++;
  }
  f.close();
  
  // NOTE answer here
  std::cout << count << "\n";
} // main

static bool is_safe(std::vector<int>& v, const bool& _is_already_dampened) {
  bool _line_validity = true;
  
  if (v.at(0) > v.at(1)) { // if its strictly decreasing
    for (int i = 1; i < v.size(); i++) {
      if (!(v.at(i - 1) - 1 >= v.at(i) && v.at(i - 1) - 3 <= v.at(i))) {
        if (!_is_already_dampened) {
          v.erase(v.begin() + i);
          is_safe(v, true);
        }
        _line_validity = false;
      }
    }
  } else if (v.at(0) < v.at(1)) { // if its strictly increasing
    for (int i = 1; i < v.size(); i++) {
      if (!(v.at(i - 1) + 1 <= v.at(i) && v.at(i - 1) + 3 >= v.at(i))) {
        if (!_is_already_dampened) {
          v.erase(v.begin() + i);
          is_safe(v, true);
        }
        _line_validity = false;
      }
    }
  } else { // if its equal, its not strictly monotonic (and therefore its non-safe)
    if (!_is_already_dampened) {
      v.erase(v.begin() + 1);
      is_safe(v, true);
    }
    _line_validity = false;
  }
  
  return _line_validity;
}
