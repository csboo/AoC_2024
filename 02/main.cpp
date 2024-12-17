// DAY 2
#include "../include/read_from_cli.hpp"

#include <cassert>
#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

static bool is_safe(std::vector<int>& v, const bool& _is_already_dampened = false);

int main(int argc, char* argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
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
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << (end - start).count();
} // main

static bool is_safe(std::vector<int>& v, const bool& _is_already_dampened) {
  // std::cerr << "On report: { ";
  // for (const auto& i: v) {
    // std::cerr << i << " ";
  // }
  // std::cerr << "}\n";
  if (v.size() == 1) {
    // std::cerr << "report was safe\n\n";
    return true;
  }
  if (v.at(0) > v.at(1)) { // if its strictly decreasing
    for (int i = 1; i < v.size(); i++) {
      if (v.at(i - 1) - 1 < v.at(i) || v.at(i - 1) - 3 > v.at(i)) {
        // std::cerr << "Non-safe level: (vector.at(" << i << ")) -> " << v.at(i) << "\n";
        if ((i == 1 || i == 2) && !_is_already_dampened) {
          std::vector<int> copy = v;
          copy.erase(copy.begin());
          if (is_safe(copy, true)) {
            return true;
          } else {
            copy = v;
            copy.erase(copy.begin() + 1);
            if (is_safe(copy, true)) {
              return true;
            }
          }
        }
        if ( ((i < v.size() - 1 && (v.at(i + 1) < v.at(i - 1))) || i == v.size() - 1 ) && !_is_already_dampened) {
          // std::cerr << "Not yet dampened, deleting: " << *(v.begin() + i) << "\n";
          v.erase(v.begin() + i);
          // std::cerr << "dampened report: { ";
          // for (const auto& i: v ) {
            // std::cerr << i << " ";
          // }
          // std::cerr << "}\n\n";
          return is_safe(v, true);
        } 
        // _is_already_dampened? std::cerr << "Already dampened, but still " : std::cerr << "It isn't even worth dampening, ";

        // std::cerr << "report was non-safe\n\n";
        return false;
      } 
    }
  } else if (v.at(0) < v.at(1)) { // if its strictly increasing
    for (int i = 1; i < v.size(); i++) {
      if (v.at(i - 1) + 1 > v.at(i) || v.at(i - 1) + 3 < v.at(i)) {
        // std::cerr << "Non-safe level: (vector.at(" << i << ")) -> " << v.at(i) << "\n";
        if ((i == 1 || i == 2) && !_is_already_dampened) {
          std::vector<int> copy = v;
          copy.erase(copy.begin());
          if (is_safe(copy, true)) {
            return true;
          } else {
            copy = v;
            copy.erase(copy.begin() + 1);
            if (is_safe(copy, true)) {
              return true;
            }
          }
        }
        if ( ((i < v.size() - 1 && (v.at(i + 1) > v.at(i - 1))) || i == v.size() - 1 ) && !_is_already_dampened) {
          // std::cerr << "Not yet dampened, deleting: " << *(v.begin() + i) << "\n";
          v.erase(v.begin() + i);
          // std::cerr << "dampened report: { ";
          // for (const auto& i: v ) {
            // std::cerr << i << " ";
          // }
          // std::cerr << "}\n\n";
          return is_safe(v, true);
        } 
        // _is_already_dampened? std::cerr << "Already dampened, but still " : std::cerr << "It isn't even worth dampening, ";

        // std::cerr << "report was non-safe\n\n";
        return false;
      }
    }
    // std::cerr << "report was safe\n\n";
    return true;
  } else { // is must be equal, its not strictly monotonic (and therefore its non-safe)
    // std::cerr << "Non-safe level: (vector.at(" << 1 << ")) -> " << v.at(1) << "\n";
    if (!_is_already_dampened) {
      // std::cerr << "Not yet dampened, deleting: " << *(v.begin() + 1) << "\n";
      v.erase(v.begin() + 1);
      // std::cerr << "dampened report: { ";
      // for (const auto& i: v ) {
        // std::cerr << i << " ";
      // }
      // std::cerr << "}\n\n";
      return is_safe(v, true);
    } 
    // _is_already_dampened? std::cerr << "Already dampened, but still " : std::cerr << "It isn't even worth dampening, ";

    // std::cerr << "report was non-safe\n\n";
    return false;
  }
  // std::cerr << "report was safe\n\n";
  return true;
}
