#ifndef FORMAT_STRING_HH
#define FORMAT_STRING_HH

#include <ostream>
#include "str.hh"
#include <tuple>

namespace vic {

template <typename T>
struct format_string {
  using char_type = typename str<T>::char_type;
  using string = std::basic_string<char_type>;

  str<T> fmt_;

  template <typename... Args>
  constexpr string operator()(Args&&... a) const {
    auto v = as_string(std::forward<Args>(a)...);

    string s{""};
    auto it = std::begin(v);
    for (auto i = std::begin(fmt_), j = std::begin(fmt_); i < std::end(fmt_);
         i = j + 1) {
      j = std::find(i, std::end(fmt_), '%');
      s.append(i, std::distance(i, j));
      if (j != std::end(fmt_)) s.append(*it++);
    }

    return s;
  }

  template <typename... Arg>
  constexpr std::pair<int, int> check(Arg&&... a) const {
    return {argc(), sizeof...(a)};
  }

  friend std::ostream& operator<<(std::ostream& out, const format_string& s) {
    return (out << s.fmt_);
  }

  constexpr int argc() const { return fmt_.count(static_cast<char_type>('%')); }

  constexpr size_t operator[](size_t cnt) const {
    return fmt_.find(static_cast<char_type>('%'), cnt);
  }
};

constexpr auto operator"" _fmt(const char* s, size_t size) {
  return format_string<char>{str<char>{s, size}};
}

// constexpr auto operator ""_fmt(const char16_t* s, size_t size)
//{
//  return format_string<char16_t>{str<char16_t>{s, size}};
//}
}

#endif  // FORMAT_STRING_HH
