#include "RabinKarpAlgorithm.hpp"

// файл с определениями
typedef unsigned long long ull;

namespace itis {
  ull mod2pow31sub1(ull n) {
    const ull s = 31;                    // s > 0
    const ull d = (ull(1) << s) - 1;  // so d is either 1, 3, 7, 15, 31, ...).
    ull m;                               // n % d goes here.

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

  ull randsizet(ull min, ull max) {
      ull result = ull(rand() % (max-min+1) + min);
      return result;
  }
  std::vector<int> search(std::string &sub, std::string &source) {
    std::vector<int> found_subs{};
    ull const source_len = static_cast<int>(source.length());
    ull const sub_len = static_cast<int>(sub.length());
    if (source_len == 0 || sub_len == 0) {
      return found_subs;
    }
    ull constexpr prime_q = (ull(1) << 31) - 1; // it's (2^31 - 1)
    ull const x = randsizet(2, prime_q - 1);

    ull sub_hash = 0;
    ull source_hash = 0; // хэш текущей части текста
    ull x_pow = 1; // x^(sub_len - 1) % prime_q

    int i;
    int j;

    for (i = 0; i < sub_len - 1; i++) {
      x_pow = mod2pow31sub1(x_pow * x);
    }
//  3210
//  bcde ((old - a*x_pow)*x + e)%prime_q
//  abcd (((0*x +a)*x +b)*x +c)*x + d

    // calculating hash of substring and first hash of source text
    for (i = 0; i < sub_len; i++) {
      sub_hash = mod2pow31sub1(x * sub_hash + sub[i]);
      source_hash = mod2pow31sub1(x * source_hash + source[i]);
    }

    for (i = 0; i < source_len - sub_len + 1; i++) {
      if (sub_hash == source_hash) {
        // hashes are equal let's check if strings are exactly the same
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
      if (ull(i) < source_len - sub_len) {
        ull temp1 = mod2pow31sub1(x_pow * ull(source[i])); // a*x_pow
        ull temp2 = mod2pow31sub1(source_hash + prime_q - temp1); // old_sub - a*x_pow
        ull temp3 = mod2pow31sub1(x*temp2); // (old_sub - a*x_pow) * x
        source_hash = mod2pow31sub1(temp3 + ull(source[i + sub_len])); // (old_sub - a*x_pow) * x + new_char
      }
    }

    return found_subs;
  }

}  // namespace itis

