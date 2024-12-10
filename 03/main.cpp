#include "../include/read_from_cli.hpp"
#include <algorithm>
#include <cctype>
#include <forward_list>
#include <fstream>
#include <set>

char next();

bool check(char& c, const int& level);

int main(int argc, char* argv[]) {
  std::ifstream f = from_cli(argc, argv);

  std::set<char> good = {'m', 'u', 'l'};
  char c;
  int level = 0;
  std::string s_num;
  while (f.get(c)) {
    if (c == 'm') {
      level = 1;
    }
    if (level == 1 && c == 'u') {
      level++;
      continue;
    }
    if (level == 2 && c == 'l') {
      level++;
      continue;
    }
    if (level == 3 && c == '(') {
      level++;
      continue;
    }
    if (level == 4 && isdigit(c)) {
      level++;
      s_num += c;
      continue;
    }
    if (level == 5 && isdigit(c)) {
      level++;
      s_num += c;
      continue;
    }
    if (level == 6 && isdigit(c)) {
      level++;
      s_num += c;
      continue;
    }
    if (level == 7 && c == ',') {
      level++;
      continue;
    }
      if (c == 'u') {
        f.get(c);
        if (c == 'l') {
          f.get(c);
          if (c == '(') {
            f.get(c);
            if (isdigit(c)) {
              f.get(c);
              if (isdigit(c)) {
                f.get(c);
                if (isdigit(c)) {
                  f.get(c);
                  if (c == ',') {
                    
                  }
                } else {
                  if (c == ',') {
                  
                  }
                }
              } else {
                if (c == ',') {
                
                }
              }
            } else {
              if (c == ',') {
              
              }
            } 
          } 
        } 
      } 
    }
    check(c, 0);
    // if (good.count(c)) {
      
    // }
  }


  fo

  
  
  f.close();
}

bool check(char& c, const int& level) {
  if (c == 'm') {
    f.get(c);
    if (c == 'u') {
      f.get(c);
      if (c == 'l') {
        f.get(c);
        if (c == '(') {
        
        } 
      } 
    } 
  }
}
