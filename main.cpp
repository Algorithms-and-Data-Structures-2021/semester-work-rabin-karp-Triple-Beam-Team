#include <iostream>
#include "RabinKarpAlgorithm.hpp"

int main(int argc, char *argv[]) {
  std::string text = "Every time i look down on this timeless town,\n"
                     "Whether blue or gray be her skies,\n"
                     "Whether loud be her cheers, or whether soft be her tears,\n"
                     "More and more do I realize that...\n"
                     "I love Paris in the spring time\n"
                     "I love Paris in the fall\n"
                     "I love Paris in the summer when it sizzles\n"
                     "I love Paris in the winter when it drizzles\n"
                     "I love Paris every moment\n"
                     "Every moment of the year\n"
                     "I love Paris, why oh why do I love Paris\n"
                     "Because my love is here\n"
                     "\n"
                     "Performed by maestro E.Ponasenkov";
  std::string pattern = "Every moment of the year\n"
                        "I love Paris, why oh why do I love Paris\n"
                        "Because my love is here\n";
  std::vector<int> insertions = itis::search(pattern, text);
  for (int elem: insertions) {
    std::cout << elem << std::endl;
  }
  return 0;
}