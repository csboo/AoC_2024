// DAY 2


#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

static inline bool is_safe(const std::string& line) {
  std::istringstream iss(line);
  
  int i1, i2;
  while (iss >> i1 >> i2) {
    if (i1 > i2) {
      if (!(i1 + 1 <= i2 && i1 + 3 >= i2)) {
        return false;
      }
    } else if (i1 < i2) {
      if (!(i1 - 1 >= i2 && i1 - 3 <= i2)) {
        return false;
      }
    } else if (i1 == i2) {
      return false;
    }
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
}
