#ifndef SHELL_H
#define SHELL_H

#include "laba10.h"
#include "laba11.h"
#include "laba12.h"

class Shell
{
public:
  Shell();
  ~Shell();
  void start();

private:
  Laba10 *laba10 = nullptr;
  Laba11 *laba11 = nullptr;
  Laba12 *laba12 = nullptr;
  void printPrompt();
  void execTask(int task);
};

#endif // SHELL_H
