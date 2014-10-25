#ifndef STR_HH
#define STR_HH

#include "algo.hh"

namespace vic {

template <typename T>
struct str {
  using char_type = T;
  using string = std::basic_string<char_type>;
  using iterator = const char_type*;

  template <size_t N>
  constexpr str(const char_type (&a)[N])
      : p_{a}, sz_{N} {}

  constexpr str(const char_type* a, size_t N) : p_{a}, sz_{N} {}

  explicit operator std::basic_string<char_type>() const { return {p_, sz_}; }

  friend std::ostream& operator<<(std::ostream& out, const str& s) {
    out.write(s.p_, s.sz_);
    return out;
  }

  constexpr iterator begin() const { return p_; }

  constexpr iterator end() const { return p_ + sz_; }

  constexpr int count(char_type c) const {
    return vic::count(begin(), end(), c);
  }

  constexpr int find(char_type c, size_t cnt) const {
    for (int pos = 0; pos < sz_; ++pos)
      if ((*this)[pos] == c) {
        if (cnt == 0) return pos;
        --cnt;
      }
    return sz_;
  }

  constexpr char_type operator[](size_t pos) const { return *(p_ + pos); }

 private:
  const T* const p_;
  const size_t sz_;
};
}

#endif  // STR_HH
