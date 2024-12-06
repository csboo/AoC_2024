// DAY 2
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

static inline bool is_safe(const std::string& line) {
  std::istringstream iss(line);
  
  int num;
  std::vector<int> v;
    while (iss >> num) {
    v.push_back(num);
  }
  if (v.at(0) > v.at(1)) { // if its strictly decreasing
    for (int i = 1; i < v.size(); i++) {
      if (!(v.at(i - 1) - 1 >= v.at(i) && v.at(i - 1) - 3 <= v.at(i))) {
        return false;
      }
    }
  } else if (v.at(0) < v.at(1)) { // if its strictly increasing
    for (int i = 1; i < v.size(); i++) {
      if (!(v.at(i - 1) + 1 <= v.at(i) && v.at(i - 1) + 3 >= v.at(i))) {
        return false;
      }
    }
  } else { // if its equal, its not strictly monotonic (and therefore its non-safe)
    return false;
  }

  return true;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "You must provide only 1 argument!\n";
    exit(1);
  }
  std::ifstream f(argv[1]);  
  if (!f.is_open()) {
    std::cerr << "Error while opening file: " << argv[1] << "\n";
    exit(1);
  }

  std::string line;
  int count = 0;
  while (std::getline(f, line)) {
    if (is_safe(line)) count++;
  }
  f.close();

  std::cout << count << "\n";
} // main
