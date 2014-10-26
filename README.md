cpp-str-fmt
===========

This library aims to offer a simple C++ interface for string formatting by making use of modern (c++14) language features.

Here is a short example of what the syntax looks like:
```cpp
  constexpr auto f = "Hello, %!\n"_fmt;
  std::cout << f("world");
```

And a somewhat longer one:
```cpp
  constexpr auto bottles = R"(
      % bottles of beer on the wall, % bottles of beer.
      If one of those bottles should happen to fall,
                     % bottle% of beer on the wall....
  )"_fmt;

  for (int i = 99; i > 1; --i)
    std::cout << bottles(i, i, i - 1, (i - 1 > 1) ? "s" : "");

  std::cout << R"(
      If that one bottle should happen to fall,
                     what a waste of alcohol!)" << std::endl;
```
