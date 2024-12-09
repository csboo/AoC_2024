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
  std::cerr << "On report: ";
  for (const auto& i: v) {
    std::cerr << i << " ";
  }
  std::cerr << "\n";
  if (v.at(0) > v.at(1)) { // if its strictly decreasing
    for (int i = 1; i < v.size(); i++) {
      std::cout << "testfor1\n";
      if (!(v.at(i - 1) - 1 >= v.at(i) && v.at(i - 1) - 3 <= v.at(i))) {
        std::cout << "testif\n";
        if ((v.at(i + 1) < v.at(i - 1)) && !_is_already_dampened) {
          std::cout << "deleting: " << *v.begin() + i - 1 << "\n";
          v.erase(v.begin() + (i - 1) );
          return is_safe(v, true);
        } 
      }
      return false;
    }
  } else if (v.at(0) < v.at(1)) { // if its strictly increasing
    for (int i = 1; i < v.size(); i++) {
      if (!(v.at(i - 1) + 1 <= v.at(i) && v.at(i - 1) + 3 >= v.at(i))) {
        std::cerr << "Non-safe level: (vector.at(" << i + 1 << ")) -> " << i << "\n";
        if (i < v.size() && (v.at(i + 1) > v.at(i - 1) ) && !_is_already_dampened) {
          std::cerr << "Not yet dampened, deleting: " << *(v.begin() + (i - 1)) << "\n";
          v.erase(v.begin() + (i - 1) );
          std::cerr << "dampened report: ";
          for (const auto& i: v ) {
            std::cerr << i << " ";
          }
          std::cerr << "\n\n";
          return is_safe(v, true);
        } 
        std::cerr << "\n\n";
        return false;
      }
    }
    std::cerr << "\n\n";
    return true;
  } else { // is must be equal, its not strictly monotonic (and therefore its non-safe)
    std::cerr << "Non-safe level: (vector.at(" << 1 << ")) -> " << 1 << "\n";
    if (2 < v.size() && !_is_already_dampened) {
      std::cerr << "Not yet dampened, deleting: " << *(v.begin() + 1) << "\n";
      v.erase(v.begin());
      std::cerr << "dampened report: ";
      for (const auto& i: v ) {
        std::cerr << i << " ";
      }
      std::cerr << "\n\n";
      return is_safe(v, true);
    } 
    std::cerr << "\n\n";
    return false;
  }
  return false;
}
