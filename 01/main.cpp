// DAY one
#include "../include/read_from_cli.hpp"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>


static inline void part1(std::priority_queue<int>& q1, std::priority_queue<int>& q2, int& S) {
  int sum = 0;
  assert(q1.size() == 1000);
  S = q1.size();
  auto tempasdq2 = q2;
  auto tempasdq1 = q1;
  for (int i = 0; i < S; i++) {
    sum += abs(tempasdq1.top() - tempasdq2.top());
    tempasdq1.pop(); tempasdq2.pop();
  }
  std::cout << sum << "\n";
}

static inline void part2(std::priority_queue<int>& q1, std::priority_queue<int>& q2, const int& S) {
  std::vector<int> vec_q2;
  int sim_sum = 0;
  for (; !q2.empty(); q2.pop()) {
    vec_q2.push_back(q2.top());
  }
  // std::cerr << vec_q2.size();
  assert(vec_q2.size() == 1000);
  for (int i = 0; i < S; i++, q1.pop()) {
    int key = q1.top();
    sim_sum += key * std::count(vec_q2.begin(), vec_q2.end(), key);
  }
  std::cout << sim_sum << "\n";
}

int main(int argc, char* argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  std::ifstream f = from_cli(argc, argv);
  assert(f.is_open());
  std::priority_queue<int> Q1, Q2;
  int temp;
  while (f >> temp) {
    Q1.push(temp);
    f >> temp;
    Q2.push(temp);
  }
  f.close();

  int N;
  part1(Q1, Q2, N);
  // std::cerr << Q2.size() << " " << Q1.size() << "\n";
  part2(Q1, Q2, N);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "\n";
} 
