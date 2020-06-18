#include "laba12.h"

/* Задание 1.
 * Создайте класс с двумя переменными. Добавьте функцию вывода на экран и
 * функцию изменения этих переменных. Добавьте функцию, которая находит сумму
 * значений этих переменных, и функцию, которая находит наибольшее значение из
 * этих двух переменных. */
void Laba12::task1() {
  TwoVariables twoVariables;
  std::cout << "\tВведите первую переменную (целое число): ";
  int _a = 0;
  std::cin >> _a;
  twoVariables.setX(_a);
  std::cout << "\tВведите вторую переменную (целое число): ";
  std::cin >> _a;
  twoVariables.setY(_a);
  std::cout << "\tФункция вывода: ";
  twoVariables.print();
  std::cout << "\tСумма: " << twoVariables.sum() << std::endl;
  std::cout << "\tМаксимум: " << twoVariables.max() << std::endl;
  std::cin.get();
}

/******************************************************************************/

/* Задание 2.
 * Создайте класс многочленов от одной переменной, задаваемых степенью
 * многочлена и массивом коэффициентов. Предусмотрите методы для вычисления
 * значения многочлена для заданного аргумента, операции сложения, вычитания и
 * умножения многочленов с получением нового объекта-многочлена, вывод на экран
 * описания многочлена. */
void Laba12::task2() {
  std::string c1, c2;
  std::cout << "\tВведите массив коэффициентов для первого многочлена (c, x, "
               "x^2, ..., x^n) (через пробел):"
            << std::endl
            << "\t";
  getline(std::cin, c1);
  std::vector<std::string> cs1, cs2;
  boost::split(cs1, c1, [](char c) { return c == ' '; });
  std::cout << "\tВведите массив коэффициентов для второго многочлена (c, x, "
               "x^2, ..., x^n) (через пробел):"
            << std::endl
            << "\t";
  getline(std::cin, c2);
  boost::split(cs2, c2, [](char c) { return c == ' '; });
  std::vector<float> coeffs1, coeffs2;
  for (auto i : cs1)
    coeffs1.push_back(std::stof(i));
  for (auto i : cs2)
    coeffs2.push_back(std::stof(i));
  Polynomial p1(coeffs1), p2(coeffs2);
  std::cout << "\tТак выглядит первый многочлен:" << std::endl << "\t";
  p1.print();
  std::cout << "\tА так - второй:" << std::endl << "\t";
  p2.print();
  float x;
  std::cout << "\tВведите значение аргумента x: ";
  std::cin >> x;
  std::cout << "\tРезультат для первого многочлена: " << p1.count(x)
            << std::endl;
  std::cout << "\tРезультат для второго многочлена: " << p2.count(x)
            << std::endl;
  std::cout << "\tРезультат для суммы двух многочленов: " << (p1 + p2).count(x)
            << std::endl;
  std::cout << "\tРезультат для разности двух многочленов (p1 - p2): "
            << (p1 - p2).count(x) << std::endl;
  std::cout << "\tРезультат для произведения двух многочленов: "
            << (p1 * p2).count(x) << std::endl;
  std::cin.get();
}

/******************************************************************************/

/* Задание 3.
 * Составить описание класса для вектора, заданного координатами его концов в
 * трехмерном пространстве. Обеспечить операции сложения и вычитания векторов с
 * получением нового вектора (суммы или разности), вычисления скалярного
 * произведения двух векторов, длины вектора, косинуса угла между векторами. */
void Laba12::task3() {
  float x1, y1, z1, x2, y2, z2;
  std::cout << "\tВведите координаты первого вектора (через пробел): ";
  std::cin >> x1 >> y1 >> z1;
  std::cout << "\tВведите координаты второго вектора (через пробел): ";
  std::cin >> x2 >> y2 >> z2;
  Vector3 v1(x1, y1, z1), v2(x2, y2, z2);
  std::cout << "\tДлина первого вектора: " << v1.length() << std::endl;
  std::cout << "\tДлина второго вектора: " << v2.length() << std::endl;
  Vector3 v_sum = v1 + v2;
  std::cout << "\tДлина суммарного вектора: " << v_sum.length() << std::endl;
  printf("\tКоординаты суммарного вектора: %.3f, %.3f, %.3f\n", v_sum.getX(),
         v_sum.getY(), v_sum.getZ());
  Vector3 v_diff1 = v1 - v2, v_diff2 = v2 - v1;
  std::cout << "\tДлина вектора разности (v1 - v2): " << v_diff1.length()
            << std::endl;
  printf("\tКоординаты вектора разности (v1 - v2): %.3f, %.3f, %.3f\n",
         v_diff1.getX(), v_diff1.getY(), v_diff1.getZ());
  std::cout << "\tДлина вектора разности (v2 - v1): " << v_diff2.length()
            << std::endl;
  printf("\tКоординаты вектора разности (v2 - v1): %.3f, %.3f, %.3f\n",
         v_diff2.getX(), v_diff2.getY(), v_diff2.getZ());
  printf("\tСкалярное произведение двух векторов: %.5f\n", v1.dot(v2));
  printf("\tКосинус угла между векторами: %.5f\n", v1.cos(v2));
  std::cin.get();
}

/******************************************************************************/

/* Задание 4.
 * Создайте класс Matrix, объекты которого могут быть проинициализированы с
 * клавиатуры или из файла. Для хранения матрицы используйте динамический
 * массив, обеспечьте (перегрузите) для объектов этого класса операции сложения,
 * вычитания и умножения с созданием объекта такого же класса.  */
void Laba12::task4() {
  std::vector<Matrix> matrices;
  for (ushort i = 0; i < 2; i++) {
    ushort opt = 0;
    std::cout << "\tЗаполнение матрицы №" << i + 1
              << ". Выберите опцию:" << std::endl;
    std::cout << "\t1.  Считать матрицу с клавиатуры" << std::endl;
    std::cout << "\t2.  Считать матрицу с файла" << std::endl << "\t>>> ";
    std::cin >> opt;
    if (opt == 1) {
      std::cout << "\tВводите матрицу построчно (элементы одной строки - через "
                   "пробел):"
                << std::endl;
      std::vector<std::vector<float>> A;
      std::cin.get();
      while (true) {
        std::string str;
        std::cout << "\t";
        getline(std::cin, str);
        if (str.empty())
          break;
        std::vector<std::string> splitted;
        boost::split(splitted, str, [](char c) { return c == ' '; });
        std::vector<float> line;
        for (auto i : splitted)
          line.push_back(std::stof(i));
        A.push_back(line);
      }
      matrices.push_back(Matrix(A));
    } else if (opt == 2) {
      std::string filename;
      std::cout << "\tВведите имя файла: ";
      std::cin >> filename;
      std::ifstream f(filename);
      std::string tmp_line;
      float tmp_num;
      ulong len_i = 1, len_j = 0;
      getline(f, tmp_line);
      std::istringstream *iss = new std::istringstream(tmp_line);
      while (*iss >> tmp_num)
        len_j++;
      delete iss;
      while (getline(f, tmp_line))
        len_i++;
      f.clear();
      f.seekg(0);
      std::vector<std::vector<float>> A;
      for (ulong i = 0; i < len_i; i++) {
        std::vector<float> line;
        for (ulong j = 0; j < len_j; j++) {
          float k;
          f >> k;
          line.push_back(k);
        }
        A.push_back(line);
      }
      matrices.push_back(Matrix(A));
    } else
      return;
  }
  std::cout << "\tПервая матрица:" << std::endl;
  matrices[0].print();
  std::cout << "\tВторая матрица:" << std::endl;
  matrices[1].print();
  std::cout << "\tПродукт сложения:" << std::endl;
  (matrices[0] + matrices[1]).print();
  std::cout << "\tПродукт вычитания (m1 - m2):" << std::endl;
  (matrices[0] - matrices[1]).print();
  std::cout << "\tПродукт вычитания (m2 - m1):" << std::endl;
  (matrices[1] - matrices[0]).print();
  std::cout << "\tПродукт умножения (m1 * m2):" << std::endl;
  (matrices[0] * matrices[1]).print();
  std::cout << "\tПродукт умножения (m2 * m1):" << std::endl;
  (matrices[1] * matrices[0]).print();
}

void Laba12::examenation_task1() {
  std::ofstream f("OUTPUT.TXT");
  std::string str;
  std::cout << "\tВведите 9 цифр: ";
  std::cin >> str;
  int sum = 0;
  for (ushort i = 0; i < 9; i++) {
    std::cout << "\t  " << int(str[i] - '0') << " " << str[i] << std::endl;
    sum += int(str[i] - '0') * (10 - i);
  }
  for (ushort i = 0; i < 10; i++)
    if ((sum + i) % 11 == 0) {
      f << str << std::to_string(i) << std::endl;
      std::cout << "\t" << str << std::to_string(i) << std::endl;
      f.close();
      break;
    }
  std::cin.get();
}
