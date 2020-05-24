#ifndef LABA10_H
#define LABA10_H

#include <boost/algorithm/string.hpp>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

#include "additivemethods.h"

class Laba10 {
public:
  static void example1();
  static void exercise1();
  static void exercise2();
  static void task1_a();
  static void task1_b();
  static void task_add_1();

private:
  static auto readGoodWord(decltype(std::string::iterator()) iter,
                           decltype(std::string::iterator()) end)
      -> decltype(std::string::iterator());
  static bool readGoodWord();
};

#endif // LABA10_H
