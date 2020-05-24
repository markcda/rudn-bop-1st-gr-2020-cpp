#include "laba10.h"

// Пример 1.
void Laba10::example1() {
  int cntr = 0;
  std::cout << "Введите слово из скобок: ";
  std::string str;
  std::cin >> str;
  std::cin.get();
  for (auto sym : str) {
    if (sym == '(')
      cntr++;
    else if (sym == ')')
      if (--cntr < 0)
        break;
  }
  if (not cntr)
    std::cout << "Правильное выражение." << std::endl;
  else
    std::cout << "Неправильное выражение." << std::endl;
}

/* Упражнение 1. Сложные скобочные выражения.
 * Напишите программу, проверяющую правильность скобочного выражения, состоящей
 * из трёх типов скобок: ( ) { } [ ]. Используйте стек, в который будут
 * помещаться приходящие открывающие скобки. Если очередной символ c —
 * закрывающаяся скобка, то выполняйте команду "a = pop()" и проверяйте
 * совпадение типов скобок, находящихся в переменных c и a. */
/* Примечание: в C++ используется "a = stack.top(); stack.pop();" */
void Laba10::exercise1() {
  std::stack<char, std::vector<char>> stack;
  bool err = false;
  const char openers[] = "([{", closers[] = ")]}";
  std::cout << "Введите слово из скобок: ";
  std::string str;
  std::cin >> str;
  std::cin.get();
  for (auto sym : str) {
    if (AdditiveMethods::contains(sym, openers, 3))
      stack.push(sym);
    else if (AdditiveMethods::contains(sym, closers, 3)) {
      if (stack.empty()) {
        err = true;
        break;
      }
      char sym1 = stack.top();
      if (((sym1 == openers[0]) and (sym == closers[0])) or
          ((sym1 == openers[1]) and (sym == closers[1])) or
          ((sym1 == openers[2]) and (sym == closers[2]))) {
        stack.pop();
      } else {
        err = true;
        break;
      }
    }
  }
  if (not err)
    std::cout << "Правильное выражение." << std::endl;
  else
    std::cout << "Неправильное выражение." << std::endl;
}

/* Упражнение 2.
 * Напишите программу, которая перебирает все скобочные выражения с одним типом
 * скобок длины 2n, проверяет их на правильность и выводит только правильные
 * скобочные структуры. */
void Laba10::exercise2() {
  int n;
  std::cout << "Введите число n: ";
  std::cin >> n;
  std::cin.get();
  n *= 2;
  int max = pow(2, n);
  for (int i = 0; i < max; i++) {
    int cntr = 0;
    for (int j = 0; j < n; j++) {
      if (not((i >> j) & 1))
        cntr++;
      else
        cntr--;
      if (cntr < 0)
        break;
    }
    if (not cntr) {
      for (int j = 0; j < n; j++)
        std::cout << ((not((i >> j) & 1)) ? '(' : ')');
      std::cout << std::endl;
    }
  }
}

/* Задание 1.
 * Задача про «хорошие» слова. 169
 * Назовём слово хорошим, если выполнено одно из условий:
 * • Оно равно слову «0».
 * • Оно начинается на символ «1», а затем следует хорошее слово.
 * • Оно начинается на символ «2», а затем следует два записанных друг за другом
 * хороших слова.
 * • Оно начинается на символ «3», а затем следует три записанных
 * друг за другом хороших слова.
 * Примеры хороших слов: 10, 200, 3000, 21010, 2010, 3020010, 11111110,
 * 30011111110.
 * Множество хороших слов можно определить формально с помощью
 * правил вывода:
 * S ::= ’0’
 * S ::= ’1’ S
 * S ::= ’2’ S S
 * S ::= ’3’ S S S
 * Эти четыре правила являются формальной записью данного словесного описания.
 * а) Напишите программу на языке Си, которая получает на вход слово в алфавите
 * B = {0, 1, 2, 3} и определяет, «хорошее» оно или нет.
 * Подсказка: напишите рекурсивную функцию read_good_word:
 * ```
 * char* read_good_word (char *word);
 * ```
 * Она получает указатель типа char* и пробует прочитать «хорошее» слово,
 * начиная с указанного символа. Функция возвращает указатель на место того
 * символа, до которого она «дочитала». Если во время чтения встречается ошибка
 * (присутствует символ, не принадлежащий алфавиту), функция должна вернуть
 * указатель равный данному в аргументе (не смогла прочитать ни одного символа).
 */
auto Laba10::readGoodWord(decltype(std::string::iterator()) iter,
                          decltype(std::string::iterator()) end)
    -> decltype(std::string::iterator()) {
  if (iter == end)
    return iter;
  if (*iter == '0')
    return ++iter;
  if (*iter == '1')
    return Laba10::readGoodWord(++iter, end);
  if (*iter == '2')
    return Laba10::readGoodWord(Laba10::readGoodWord(++iter, end), end);
  if (*iter == '3')
    return Laba10::readGoodWord(
        Laba10::readGoodWord(Laba10::readGoodWord(++iter, end), end), end);
  else
    return iter;
}

void Laba10::task1_a() {
  std::string str;
  std::cout << "Введите слово (без пробелов, состоит только из цифр): ";
  std::cin >> str;
  std::cin.get();
  if (Laba10::readGoodWord(str.begin(), str.end()) == str.end())
    std::cout << "Слово хорошее!" << std::endl;
  else
    std::cout << "Слово плохое." << std::endl;
}

/* б) Решите эту же задачу однопроходным алгоритмом, не используя массивов.
 * Для чтения символов из потока ввода пользуйтесь функцией getchar.
 * Напишите функцию "int read_good_word();", которая считывает из потока ввода
 * только хорошее слово, а лишние символы, которые идут за хорошим словом,
 * оставляет в потоке. Если из потока удалось прочитать хорошее слово, функция
 * возвращает 1, а иначе — 0. */
bool Laba10::readGoodWord() {
  std::string str;
  std::cin >> str;
  std::cin.get();
  int cntr = 1;
  for (auto sym : str) {
    cntr--;
    if (sym == '0') {
      if (not cntr)
        return true;
    } else if (sym == '1')
      cntr++;
    else if (sym == '2')
      cntr += 2;
    else if (sym == '3')
      cntr += 3;
    else
      break;
  }
  return not cntr;
}

void Laba10::task1_b() {
  std::cout << "Введите слово (без пробелов, состоит только из цифр): ";
  bool status = Laba10::readGoodWord();
  std::cout << "Результат: хорошее слово " << (not status ? "не " : "")
            << "было найдено." << std::endl;
}

/* Дополнительное задание 1. Калькулятор выражений в постфиксной нотации. */
void Laba10::task_add_1() {
  std::cout << "Введите выражение в постфиксной нотации (используйте числа и "
               "четыре основные математические операции, разделяйте операнды "
               "пробелами): ";
  std::string text;
  std::getline(std::cin, text);
  std::vector<std::string> words;
  boost::split(words, text, [](char c) { return c == ' '; });
  // Разобьём их на левые и правые и будем искать равенство в левых и правых
  std::vector<float> lnums, rnums;
  char operations[] = "+-*/";
  for (auto word : words) {
    if (not AdditiveMethods::contains(word[0], operations, 4)) {
      if (not rnums.empty()) {
        lnums.push_back(rnums.at(rnums.size() - 1));
        rnums.pop_back();
      }
      rnums.push_back(std::stof(word));
    } else {
      if (lnums.empty() or rnums.empty()) {
        std::cout << "Нельзя обработать эту строку." << std::endl;
        return;
      }
      if (word[0] == operations[0]) {
        float a = lnums.at(lnums.size() - 1);
        lnums.pop_back();
        float b = rnums.at(rnums.size() - 1);
        rnums.pop_back();
        rnums.push_back(a + b);
      } else if (word[0] == operations[1]) {
        float a = lnums.at(lnums.size() - 1);
        lnums.pop_back();
        float b = rnums.at(rnums.size() - 1);
        rnums.pop_back();
        rnums.push_back(a - b);
      } else if (word[0] == operations[2]) {
        float a = lnums.at(lnums.size() - 1);
        lnums.pop_back();
        float b = rnums.at(rnums.size() - 1);
        rnums.pop_back();
        rnums.push_back(a * b);
      } else {
        float b = rnums.at(rnums.size() - 1);
        if (b == 0) {
          std::cout << "На ноль делить нельзя!" << std::endl;
          return;
        }
        rnums.pop_back();
        float a = lnums.at(lnums.size() - 1);
        lnums.pop_back();
        rnums.push_back(a / b);
      }
    }
  }
  std::cout << "Результат вычислений: " << rnums.at(rnums.size() - 1)
            << std::endl;
}
