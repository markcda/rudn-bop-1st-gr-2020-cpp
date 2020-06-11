#ifndef LABA11_H
#define LABA11_H

#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include <vector>

class Laba11 {
public:
  static void example1();
  static void exercise1_dot1();
  static void exercise1_dot2();
  static void exercise1_dot3();
  static void exercise1_dot4();
  static void exercise2_dot1();
  static void exercise2_dot2();
  static void exercise3();
  static void task1();
  static void task2();
  static void task3();
  static void task4();

private:
  static bool exe_check(std::string filename);
  static void about_each_symbol_in_string(const std::string &s);
};

#endif // LABA11_H
