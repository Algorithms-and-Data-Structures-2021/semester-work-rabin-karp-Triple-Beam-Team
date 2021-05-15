#pragma once
#include <vector>
#include <string>
// Заголовочный файл с объявлением структуры данных

namespace itis {
  size_t mod2pow61sub1(size_t n);
  size_t randsizet(size_t min, size_t max);
  std::vector<int> search(std::string &sub, std::string &source);

}  // namespace itis