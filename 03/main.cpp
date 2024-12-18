#include "../include/read_from_cli.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

long compute_p2(const std::string& s) {
    long sum = 0;
    const std::regex pattern_p2(R"((do\(\)|don't\(\))|mul\((\d+),(\d+)\))");
    bool _is_enabled = true;
    auto current_match = std::sregex_iterator(s.begin(), s.end(), pattern_p2);
    auto end_match = std::sregex_iterator();

    while (current_match != end_match) {
        std::smatch match = *current_match;

        // Check if it's `do()` or `don't()`
        if (!match[1].str().empty()) {
            if (match[1].str() == "do()") {
                _is_enabled = true;
            } else if (match[1].str() == "don't()") {
                _is_enabled = false;
            }
        }
        // Check if it's `mul(x, y)` and `_is_enabled` is true
        else if (_is_enabled && !match[2].str().empty() && !match[3].str().empty()) {
            int num1 = std::stoi(match[2].str());
            int num2 = std::stoi(match[3].str());
            sum += static_cast<long>(num1 * num2);
        }

        ++current_match;        
    }

    return sum;
    
}

long compute_p1(const std::string& s) {
    const std::regex pattern_p1(R"(mul\((\d+),(\d+)\))");
    long sum = 0;
    auto current_match = std::sregex_iterator(s.begin(), s.end(), pattern_p1);
    auto end_match = std::sregex_iterator();

    while (current_match != end_match) {
        std::smatch match = *current_match;
        int num1 = std::stoi(match[1].str());
        int num2 = std::stoi(match[2].str());
        sum += static_cast<long>(num1 * num2);
        ++current_match;
    }

    return sum;
}

int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream file = from_cli(argc, argv);
    std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    // std::cerr << content << "\n\n";

    std::cout << "Result for part 1: " << compute_p1(data) << "\n";
    std::cout << "Result for part 2: " << compute_p2(data) << "\n";
    
    file.close();

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "time: " << (end-start).count() << "\n";
}
