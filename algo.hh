#ifndef ALHO_HH
#define ALHO_HH

#include <iterator>
#include <vector>

namespace vic {

template <class InputIterator, class T>
constexpr typename std::iterator_traits<InputIterator>::difference_type count(
    InputIterator first, InputIterator last, const T& val) {
  typename std::iterator_traits<InputIterator>::difference_type ret = 0;
  while (first != last) {
    if (*first == val) ++ret;
    ++first;
  }
  return ret;
}

template<int N>
std::string to_string(char const (&s)[N])
{
  return std::string{s, N-1};
}

std::string to_string(const std::string& s)
{
  return s;
}

template<typename... Args>
auto as_string(Args&&... a)
{
  using std::to_string;
  using vic::to_string;
  return std::vector<std::string>{to_string(a)...};
}

}

#endif  // ALHO_HH
