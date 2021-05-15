#include <iostream>

#include "RabinKarpAlgorithm.hpp"

int main(int argc, char *argv[]) {
  std::string text = "I love Paris every moment, I love Paris every season";
  std::string pattern = "Paris";
  std::vector<int> insertions = itis::search(pattern, text);
  for (int elem: insertions) {
    std::cout << elem << std::endl;
  }
  return 0;
}