#include "laba11.h"

// Пример 1.
void Laba11::example1() {
  std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
               "Ctrl+D (Linux) / Ctrl+Z (Windows):"
            << std::endl
            << "\t";
  char ch;
  std::string s;
  while ((ch = getchar()) != EOF)
    s += ch;
  s += '\0';
  std::cin.clear(std::ios::eofbit);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\t" << s;
}

/******************************************************************************/

/* Упражнение 1.1.
 * Добавьте в программу фильтр, позволяющий принимать из потока только буквы
 * латинского алфавита и числа. */
void Laba11::exercise1_dot1() {
  std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
               "Ctrl+D (Linux) / Ctrl+Z (Windows):"
            << std::endl
            << "\t";
  char ch;
  std::string s;
  while ((ch = getchar()) != EOF)
    if (std::isalnum(ch))
      s += ch; // принимает не только буквы латиницы
  s += '\0';
  std::cin.clear(std::ios::eofbit);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\t" << s;
}

/******************************************************************************/

/* Упражнение 1.2.
 * Добавьте в программу автозамену: при вводе символов "Z" и "9" вместо них
 * должен сохраняться символ окончания строки "\0". */
void Laba11::exercise1_dot2() {
  std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
               "Ctrl+D (Linux) / Ctrl+Z (Windows):"
            << std::endl
            << "\t";
  char ch;
  std::string s;
  while ((ch = getchar()) != EOF)
    if (ch != 'Z' and ch != '9')
      s += ch;
    else
      s += '\0';
  s += '\0';
  std::cin.clear(std::ios::eofbit);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\t" << s;
}

/******************************************************************************/

/* Упражнение 1.3.
 * Замените в операции вывода функцию printf() на putchar() так, чтобы результат
 * работы программы не изменился. */
void Laba11::exercise1_dot3() {
  std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
               "Ctrl+D (Linux) / Ctrl+Z (Windows):"
            << std::endl
            << "\t";
  char ch;
  std::string s;
  while ((ch = getchar()) != EOF)
    if (ch != 'Z' and ch != '9')
      s += ch;
    else
      s += '\0';
  s += '\0';
  std::cin.clear(std::ios::eofbit);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\t";
  for (auto ch : s)
    std::putchar(ch);
}

/******************************************************************************/

/* Упражнение 1.4.
 * Измените код программы так, чтобы все символы выводились в одну строчку, а
 * вместо символа "\n" всегда, кроме последнего, выводился "_". */
void Laba11::exercise1_dot4() {
  std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
               "Ctrl+D (Linux) / Ctrl+Z (Windows):"
            << std::endl
            << "\t";
  char ch;
  std::string s;
  while ((ch = getchar()) != EOF)
    if (ch != 'Z' and ch != '9')
      s += ch;
    else
      s += '\0';
  s += '\0';
  std::cin.clear(std::ios::eofbit);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\t";
  for (auto ch : s)
    if (ch != '\n')
      std::putchar(ch);
    else
      std::putchar('_'); // упражнение не доделано: последний переход строки
                         // тоже заменяется на нижнее подчёркивание
}

/******************************************************************************/

/* Упражнение 2.1.
 * Введите новые переменные:
 *  FILE* file_out = stdout;
 *  FILE* file_in  = stdin;
 * и замените getchar() на getc(file_in), а putchar(a) - на putc(a, stdout). */
void Laba11::exercise2_dot1() {
  std::istream *file_in;
  std::ostream *file_out;
  file_in = &std::cin;
  file_out = &std::cout;
  std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
               "Ctrl+D (Linux) / Ctrl+Z (Windows):"
            << std::endl
            << "\t";
  char ch;
  std::string s;
  while (not file_in->eof()) {
    file_in->get(ch);
    if (ch != 'Z' and ch != '9')
      s += ch;
    else
      s += '\0';
  }
  s += '\0';
  std::cin.clear(std::ios::eofbit);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\t";
  for (auto ch : s)
    if (ch != '\n')
      file_out->put(ch);
    else
      file_out->put('_'); // упражнение не доделано: последний переход строки
                          // тоже заменяется на нижнее подчёркивание
  delete file_in;
  delete file_out;
}

/******************************************************************************/

/* Упражнение 2.2.
 * Замените в определении переменных file_out и file_in stdout на fopen
 * ("FileOUT.txt", "r"), а stdin - на fopen ("FileIN.txt", "w"). Скопируйте
 * содержимое файла FileIN.txt в FileOUT.txt. */
void Laba11::exercise2_dot2() {
  const static int BUF_SIZE = 4096;
  std::cout
      << "\tВведите имя файла, из которого мы будем копировать информацию: ";
  std::string in_fn;
  std::cin >> in_fn;
  std::ifstream file_in(in_fn, std::ios_base::in | std::ios_base::binary);
  std::cout
      << "\tВведите имя файла, в который мы будем копировать информацию: ";
  std::string out_fn;
  std::cin >> out_fn;
  std::ofstream file_out(out_fn, std::ios_base::out | std::ios_base::binary);
  std::cout << "\tКопируем содержимое " << in_fn << " в " << out_fn << "."
            << std::endl;
  char buf[BUF_SIZE];
  do {
    file_in.read(&buf[0], BUF_SIZE);
    file_out.write(&buf[0], file_in.gcount());
  } while (file_in.gcount() > 0);
  file_in.close();
  file_out.close();
  std::cout << "\tКопирование завершено." << std::endl;
}

/******************************************************************************/

/* Упражнение 3.
 * Допишите программу следующим образом: после закрытия файла выводится запрос
 * на то, какой элемент массива надо напечатать, после чего из файла считывается
 * и выводится на экран соответствующий элемент. Запрос повторяется в цикле,
 * пока пользователь не нажмёт Enter без ввода дополнительной информации. */
void Laba11::exercise3() {
  int m, n, i, j;
  FILE *File;
  char NameFile[] = "File.txt";
  File = fopen(NameFile, "w");
  if (File == nullptr) {
    std::cout << "\tОшибка открытия файла." << std::endl;
    return;
  }
  printf("m, n = ");
  scanf("%i %i", &m, &n);
  srand(time(nullptr));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      fprintf(File, "%8d ", rand());
    }
    fprintf(File, "\n");
  }
  fclose(File);
  while (true) {
    std::string s;
    std::cout
        << "\tВведите номер элемента из файла, который вы хотите считать: ";
    std::cin >> s;
    try {
      int i = std::stoi(s);
      int d;
      std::ifstream file(NameFile);
      for (int j = 0; j < i; j++) {
        if (not file.eof())
          file >> d;
        else {
          std::cout << "\tТакого элемента не существует." << std::endl;
          file.close();
          continue;
        }
      }
      std::cout << "\tЭлемент: " << d << std::endl;
      file.close();
    } catch (std::invalid_argument const &e) {
      std::cout << "\tBad input: std::invalid_argument thrown" << std::endl;
    } catch (std::out_of_range const &e) {
      std::cout << "\tInteger overflow: std::out_of_range thrown" << std::endl;
    }
  }
}

/******************************************************************************/

/* Задание 1.
 * В операционной системе MS-DOS первые два байта ЕХЕ-файлов равны
 * 0100110101011010. Это инициалы "MZ" создателя ЕХЕ-формата Марка Збиковски
 * (Mark Zbikowski). Напишите функцию, проверяющую эти байты у файла, заданного
 * ее аргументом, и возвращающую 1, если это ЕХЕ-файл, и 0 в противном случае.
 */
bool Laba11::exe_check(std::string filename) {
  static const char b1e = 0b01001101, b2e = 0b01011010;
  bool res = false;
  std::ifstream exe_program(filename, std::ios::in | std::ios::binary);
  char b1, b2;
  exe_program.get(b1);
  exe_program.get(b2);
  if ((b1 == b1e) and (b2 == b2e))
    res = true;
  exe_program.close();
  return res;
}

void Laba11::task1() {
  std::string filename;
  std::cout << "\tВведите имя файла: ";
  std::cin >> filename;
  std::cout << "\tРезультат проверки на *.exe: " << Laba11::exe_check(filename)
            << std::endl;
}

/******************************************************************************/

/* Задание 2.
 * Напишите программу, считывающую содержание текстового файла по строкам и
 * выводящую число символов в строке + первые 10 символов строки, при этом если
 * в строке меньше 10 символов, последний символ строки выводится столько раз,
 * сколько не хватает до 10 символов. Напишите эту программу в двух вариантах: с
 * помощью функций работы с потоками и буфером в стиле языка C и C++. */
void Laba11::task2() {
  std::string filename;
  std::cout << "\tВведите имя файла: ";
  std::cin >> filename;
  std::ifstream in(filename);
  std::string line;
  while (getline(in, line)) {
    std::cout << "\t";
    std::istringstream iss(line);
    char ch = ' '; // чтобы предупредить непредсказуемое поведение в случае
                   // пустых строк
    ushort cntr = 0;
    while ((iss.get(ch)) and (cntr < 10)) {
      std::cout << ch;
      cntr++;
    }
    while (cntr != 10) {
      std::cout << ch;
      cntr++;
    }
    std::cout << std::endl;
  }
  in.close();
  std::cin.get();
}

/******************************************************************************/

/* Задание 3.
 * Напишите программу, вычисляющую произведение матриц. При этом исходные
 * матрицы и матрица-продукт находятся в файлах, в программе может храниться
 * только по одному элементу каждой из матриц. */
// Задание сформулировано не очень точно, поэтому считается, что временные
// продукты перемножения каждой из компонент двух матриц мы можем хранить в
// памяти до тех пор, пока полностью не вычислим их.
void Laba11::task3() {
  std::string in1, in2;
  std::cout << "\tВведите название файла с первой матрицей: ";
  std::cin >> in1;
  std::cout << "\tВведите название файла со второй матрицей: ";
  std::cin >> in2;
  std::ifstream f1(in1), f2(in2);
  std::string tmp_line;
  int tmp_num;
  uint len_j_1 = 0, len_j_2 = 0;
  uint len_i_1 = 1, len_i_2 = 1;
  getline(f1, tmp_line);
  std::istringstream *iss = new std::istringstream(tmp_line);
  while (*iss >> tmp_num)
    len_j_1++;
  delete iss;
  getline(f2, tmp_line);
  iss = new std::istringstream(tmp_line);
  while (*iss >> tmp_num)
    len_j_2++;
  delete iss;
  while (getline(f1, tmp_line))
    len_i_1++;
  while (getline(f2, tmp_line))
    len_i_2++;
  f1.clear();
  f1.seekg(0);
  f2.clear();
  f2.seekg(0);
  if (len_j_1 != len_i_2) {
    std::cout << "\tМатрицы не могут быть перемножены, так как число столбцов "
                 "первой матрицы не равно числу строк второй."
              << std::endl;
    f1.close();
    f2.close();
    std::cin.get();
    return;
  }
  std::string out1;
  std::cout << "\tВведите название для файла c матрицей-продуктом: ";
  std::cin >> out1;
  std::ofstream f3(out1);
  for (uint i_1 = 0; i_1 < len_i_1; i_1++) {
    std::vector<int> line_product;
    // заполняем строку нулями
    for (unsigned i = 0; i < len_j_2; i++)
      line_product.push_back(0);
    // проходим по матрицам
    for (uint j_1 = 0; j_1 < len_j_1; j_1++) {
      int element_from_first_matrix = 0;
      if (not(f1 >> element_from_first_matrix)) {
        std::cout << "\tОшибка чтения первой матрицы." << std::endl;
        f1.close();
        f2.close();
        f3.close();
        std::cin.get();
        return;
      }
      for (uint j_2 = 0; j_2 < len_j_2; j_2++) {
        int element_from_second_matrix = 0;
        if (not(f2 >> element_from_second_matrix)) {
          std::cout << "\tОшибка чтения второй матрицы." << std::endl;
          f1.close();
          f2.close();
          f3.close();
          std::cin.get();
          return;
        }
        line_product[j_2] +=
            element_from_first_matrix * element_from_second_matrix;
      }
    }
    f2.clear();
    f2.seekg(0);
    for (auto element : line_product)
      f3 << element << " ";
    f3 << std::endl;
  }
  f3.close();
  std::cout << "\tПроизведение матриц вычислено." << std::endl;
  std::cin.get();
}

/******************************************************************************/

/* Задание 4.
 * Напишите программу, которая воспринимает входные данные как поток символов и
 * читает их до тех пор, пока не встретит символ EOF. Источником может быть как
 * клавиатура, так и файл, на который укажет пользователь. Заставьте программу
 * распечатывать каждый входной символ и его десятичное значение. Обратите
 * внимание на то, что в последовательности ASCII символу пробела предшествуют
 * непечатаемые символы. Примените к ним специальную обработку. Если
 * непечатаемым символом является символ новой строки или символ табуляции,
 * печатайте, соответственно, '\n' или '\t'. */
void Laba11::about_each_symbol_in_string(const std::string &s) {
  for (auto ch : s) {
    std::string r;
    if (ch == '\n')
      r = "\'\\n'";
    else if (ch == '\t')
      r = "\'\\t'";
    else if (ch >= ' ') {
      r = "'";
      r += ch;
      r += "\'";
    }
    else
      r = "???";
    std::cout << "\t" << r << " " << int(ch) << std::endl;
  }
}

void Laba11::task4() {
  std::cout << "\tВыберите опцию:" << std::endl;
  std::cout << "\t1.  Ввод символов с клавиатуры" << std::endl;
  std::cout << "\t2.  Ввод символов из файла" << std::endl << "\t>>> ";
  short unsigned option = 0;
  std::cin >> option;
  if (option == 1) {
    std::cout << "\tВводите символы в буфер, а потом прекратите ввод через "
                 "Ctrl+D (Linux) / Ctrl+Z (Windows):"
              << std::endl
              << "\t";
    char ch;
    std::string s;
    while ((ch = getchar()) != EOF)
      s += ch;
    s += '\0';
    std::cin.clear(std::ios::eofbit);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Laba11::about_each_symbol_in_string(s);
  } else if (option == 2) {
    std::cout << "\tВведите имя файла: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream in(filename);
    std::string tmp_line;
    while (getline(in, tmp_line))
      Laba11::about_each_symbol_in_string(tmp_line);
    in.close();
  }
}
