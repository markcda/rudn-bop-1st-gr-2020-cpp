#include "shell.h"

Shell::Shell() { laba10 = new Laba10(); }

Shell::~Shell() { delete laba10; }

void Shell::start() {
  int option = 0;
  while (true) {
    this->printPrompt();
    std::cin >> option;
    std::cin.get();
    if (not option)
      break;
    this->execTask(option);
    std::cout << "Введите ВВОД для продолжения..." << std::endl;
    std::cin.get();
  }
}

void Shell::printPrompt() {
  using Out = void (*)(const char str[]);
  Out out = [](const char str[]) { std::cout << str << std::endl; };
  out("Привет! Выбери задание, которое хочешь проверить:");
  out(" 0) Выход");
  out(" 1) [Лаба 10] Пример 1 - Простые скобочные выражения");
  out(" 2) [Лаба 10] Упражнение 1 - Сложные скобочные выражения");
  out(" 3) [Лаба 10] Упражнение 2 - Перебор скобочных выражений");
  out(" 4) [Лаба 10] Задание 1а - Хорошее/плохое слово");
  out(" 5) [Лаба 10] Задание 1б - Хорошее/плохое слово без рекурсии");
  out(" 6) [Лаба 10] Дополнительное задание 1 - Калькулятор выражений в постфиксной нотации");
}

void Shell::execTask(int task) {
  switch (task) {
  case 1:
    laba10->example1();
    break;
  case 2:
    laba10->exercise1();
    break;
  case 3:
    laba10->exercise2();
    break;
  case 4:
    laba10->task1_a();
    break;
  case 5:
    laba10->task1_b();
    break;
  case 6:
    laba10->task_add_1();
    break;
  }
}
