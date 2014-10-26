/*
   Copyright 2014 Victor-Nicolae Savu

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


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
