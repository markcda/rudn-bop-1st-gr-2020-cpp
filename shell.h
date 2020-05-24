#ifndef SHELL_H
#define SHELL_H

#include "laba10.h"

class Shell
{
public:
  Shell();
  ~Shell();
  void start();

private:
  Laba10 *laba10 = nullptr;
  void printPrompt();
  void execTask(int task);
};

#endif // SHELL_H