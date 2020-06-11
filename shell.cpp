#include "shell.h"

Shell::Shell() {
  laba10 = new Laba10();
  laba11 = new Laba11();
}

Shell::~Shell() {
  delete laba10;
  delete laba11;
}

void Shell::start() {
  int option = 0;
  while (true) {
    this->printPrompt();
    std::cin >> option;
    std::cin.get();
    if (not option)
      break;
    this->execTask(option);
    if (std::cin.eof())
      return;
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
  out(" 6) [Лаба 10] Дополнительное задание 1 - Калькулятор выражений в "
      "постфиксной нотации");
  out(" 7) [Лаба 11] Пример 1 - Считывание потока символов");
  out(" 8) [Лаба 11] Упражнение 1.1 - Считывание букв латиницы и цифр");
  out(" 9) [Лаба 11] Упражнение 1.2 - Окончание строки вместо Z и 9");
  out("10) [Лаба 11] Упражнение 1.3 - То же, через std::putchar");
  out("11) [Лаба 11] Упражнение 1.4 - То же, вместо '\\n' - '_'");
  out("12) [Лаба 11] Упражнение 2.1 - Считывание через потоки");
  out("13) [Лаба 11] Упражнение 2.2 - Копирование файла");
  out("14) [Лаба 11] Упражнение 3 - Файловое хранилище для случайных чисел");
  out("15) [Лаба 11] Задание 1 - Проверка на *.exe");
  out("16) [Лаба 11] Задание 2 - Вывод по 10 символов строки");
  out("17) [Лаба 11] Задание 3 - Перемножение матриц");
  out("18) [Лаба 11] Задание 4 - Код каждого введённого символа");
  std::cout << ">>> ";
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
  case 7:
    laba11->example1();
    break;
  case 8:
    laba11->exercise1_dot1();
    break;
  case 9:
    laba11->exercise1_dot2();
    break;
  case 10:
    laba11->exercise1_dot3();
    break;
  case 11:
    laba11->exercise1_dot4();
    break;
  case 12:
    laba11->exercise2_dot1();
    break;
  case 13:
    laba11->exercise2_dot2();
    break;
  case 14:
    laba11->exercise3();
    break;
  case 15:
    laba11->task1();
    break;
  case 16:
    laba11->task2();
    break;
  case 17:
    laba11->task3();
    break;
  case 18:
    laba11->task4();
    break;
  }
}
