#include "RabinKarpAlgorithm.hpp"

// файл с определениями

namespace itis {
  size_t mod2pow61sub1(size_t n) {
    const size_t s = 61;                    // s > 0
    const size_t d = (size_t(1) << s) - 1;  // so d is either 1, 3, 7, 15, 31, ...).
    size_t m;                               // n % d goes here.

    for (m = n; n > d; n = m) {
      for (m = 0; n; n >>= s) {
        m += n & d;
      }
    }
    // Now m is a value from 0 to d, but since with modulus division
    // we want m to be 0 when it is d.
    m = m == d ? 0 : m;
    return m;
  }

  size_t randsizet(size_t min, size_t max) {
      size_t result = rand() % (max-min+1) + min;
      return result;
  }
  std::vector<int> search(std::string &sub, std::string &source) {
    std::vector<int> found_subs{};
    int const source_len = static_cast<int>(source.length());
    int const sub_len = static_cast<int>(sub.length());
    size_t constexpr prime_q = (size_t(1) << 61) - 1; // it's (2^61 - 1)
    size_t const x = randsizet(2, prime_q - 1);

    size_t sub_hash = 0;
    size_t source_hash = 0;
    size_t x_pow = 1; // x^(sub_len - 1) % prime_q

    int i;
    int j;

    for (i = 0; i < sub_len - 1; i++) {
      x_pow = mod2pow61sub1(x_pow * x);
    }

    // calculating hash of substring and first hash of source text
    for (i = 0; i < sub_len; i++) {
      sub_hash = mod2pow61sub1(x * sub_hash + sub[i]);
      source_hash = mod2pow61sub1(x * source_hash + source[i]);
    }

    for (i = 0; i < source_len - sub_len + 1; i++) {
      if (sub_hash == source_hash) {
        // hashs are equal let's check if strings are exactly the same
        for (j = 0; j < sub_len; j++) {
          if (sub[j] != source[i+j]) {
            break;
          }
        }

        if (j == sub_len) {
          found_subs.push_back(i);
        }
      }
      // shift of string, recomputing of hash
      if (i < source_len - sub_len) {
        size_t temp = mod2pow61sub1(x_pow * source[i]);
        source_hash = mod2pow61sub1(x * (source_hash + prime_q - temp) + source[sub_len]);
      }
    }

    return found_subs;
  }

}  // namespace itis

