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

#include <iostream>
#include "format_string.hh"
#include <tuple>
using namespace std;

enum class WeekDay {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};

std::string to_string(WeekDay day) {
  switch (day) {
    case WeekDay::Sunday:
      return {"Sunday"};
    case WeekDay::Monday:
      return {"Monday"};
    case WeekDay::Tuesday:
      return {"Tuesday"};
    case WeekDay::Wednesday:
      return {"Wednesday"};
    case WeekDay::Thursday:
      return {"Thursday"};
    case WeekDay::Friday:
      return {"Friday"};
    case WeekDay::Saturday:
    default:
      return {"Saturday"};
  }
}

struct DollarAmount {
  long double amt_;
};

auto operator"" _d(const long double amount) { return DollarAmount{amount}; }

auto to_string(DollarAmount dollars) {
  return "$"s + std::to_string(dollars.amt_);
}

int main() {
  using namespace vic;
  constexpr auto f =
      "Hello, %! How is % doing? I still owe you %."
      "Do you mind if I gave them back on %?"_fmt;

  constexpr auto check = f.check(3, 4, 3, 4);
  static_assert(check.first == check.second, "Illegal usage!");

  std::vector<std::tuple<std::string, std::string, DollarAmount, WeekDay>>
      couples{{"Dan", "Jena", 10._d, WeekDay::Saturday},
              {"Trish", "Colbie", 12._d, WeekDay::Friday},
              {"Jack", "Marcus", 5.3_d, WeekDay::Thursday}};

  for (couple : couples)
    std::cout << f(std::get<0>(couple), std::get<1>(couple),
                   std::get<2>(couple), std::get<3>(couple)) << std::endl;

  return 0;
}
