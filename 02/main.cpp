// DAY 2


#include <cstdio>
#include <fstream>
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

int main() {
  std::ifstream f("day2.txt");  

  std::string line;
  int count = 0;
  while (std::getline(f, line)) {
    if (is_safe(line)) count++;
  }
  f.close();
}
