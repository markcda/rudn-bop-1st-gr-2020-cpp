#ifndef L12CLASSES_H
#define L12CLASSES_H

#include <cmath>
#include <iostream>
#include <vector>

// Задание 1.
class TwoVariables {
public:
  TwoVariables(int x = 0, int y = 0) : _x(x), _y(y) {}
  void print() { std::cout << "(" << _x << ", " << _y << ")" << std::endl; }
  void setX(int x) { _x = x; }
  void setY(int y) { _y = y; }
  int getX() { return _x; }
  int getY() { return _y; }
  int sum() { return _x + _y; }
  int max() { return _x > _y ? _x : _y; }

private:
  int _x, _y;
};

/******************************************************************************/

// Задание 2.
class Polynomial {
public:
  Polynomial(std::vector<float> coeffs = {0.0}) : _coeffs(coeffs) {}
  std::vector<float> getCoeffs() { return _coeffs; }
  float count(float x) {
    float res = 0.0;
    for (ulong i = 0; i < _coeffs.size(); i++)
      res += pow(x, i) * _coeffs[i];
    return res;
  }
  friend Polynomial operator+(Polynomial p1, Polynomial p2) {
    std::vector<float> coeffs3;
    std::vector<float> coeffs1 = p1.getCoeffs(), coeffs2 = p2.getCoeffs();
    for (ulong i = 0; i < (coeffs1.size() > coeffs2.size() ? coeffs1.size()
                                                           : coeffs2.size());
         i++)
      coeffs3.push_back(0.0);
    for (ulong i = 0; i < coeffs3.size(); i++) {
      if (i < coeffs1.size())
        coeffs3[i] += coeffs1[i];
      if (i < coeffs2.size())
        coeffs3[i] += coeffs2[i];
    }
    return Polynomial(coeffs3);
  }
  friend Polynomial operator-(Polynomial p1, Polynomial p2) {
    std::vector<float> coeffs3;
    std::vector<float> coeffs1 = p1.getCoeffs(), coeffs2 = p2.getCoeffs();
    for (ulong i = 0; i < (coeffs1.size() > coeffs2.size() ? coeffs1.size()
                                                           : coeffs2.size());
         i++)
      coeffs3.push_back(0.0);
    for (ulong i = 0; i < coeffs3.size(); i++) {
      if (i < coeffs1.size())
        coeffs3[i] += coeffs1[i];
      if (i < coeffs2.size())
        coeffs3[i] -= coeffs2[i];
    }
    return Polynomial(coeffs3);
  }
  friend Polynomial operator*(Polynomial p1, Polynomial p2) {
    std::vector<float> coeffs3;
    std::vector<float> coeffs1 = p1.getCoeffs(), coeffs2 = p2.getCoeffs();
    for (ulong i = 0; i < coeffs1.size() + coeffs2.size(); i++)
      coeffs3.push_back(0.0);
    for (ulong i = 0; i < coeffs1.size(); i++)
      for (ulong j = 0; j < coeffs2.size(); j++)
        coeffs3[i + j] = coeffs1[i] * coeffs2[j];
    return Polynomial(coeffs3);
  }
  void print() {
    for (ulong i = 0; i < _coeffs.size(); i++) {
      if (i == 0) {
        printf("%.3f ", _coeffs[i]);
        continue;
      } else if (_coeffs[i] == 0)
        continue;
      else if (_coeffs[i] > 0)
        std::cout << "+ ";
      printf("%.3f * x", _coeffs[i]);
      if (i == 1)
        std::cout << " ";
      else
        std::cout << "^" << std::to_string(i) << " ";
    }
    std::cout << std::endl;
  }

private:
  std::vector<float> _coeffs;
};

/******************************************************************************/

// Задание 3.
class Vector3 {
public:
  Vector3(float x = 0, float y = 0, float z = 0) : _x(x), _y(y), _z(z) {}
  float length() { return sqrt(_x * _x + _y * _y + _z * _z); }
  float getX() { return _x; }
  float getY() { return _y; }
  float getZ() { return _z; }
  friend Vector3 operator+(Vector3 v1, Vector3 v2) {
    return Vector3(v1.getX() + v2.getX(), v1.getY() + v2.getY(),
                   v1.getZ() + v2.getZ());
  }
  friend Vector3 operator-(Vector3 v1, Vector3 v2) {
    return Vector3(v1.getX() - v2.getX(), v1.getY() - v2.getY(),
                   v1.getZ() - v2.getZ());
  }
  float dot(Vector3 v2) {
    return _x * v2.getX() + _y * v2.getY() + _z * v2.getZ();
  }
  float cos(Vector3 v2) { return dot(v2) / (length() * v2.length()); }

private:
  float _x = 0, _y = 0, _z = 0;
};

/******************************************************************************/

// Задание 4.
class Matrix {
public:
  Matrix(std::vector<std::vector<float>> A = {{0.0}}) : _A(A) {
    if (not validation(A))
      _A = {{0.0}};
  }
  std::vector<std::vector<float>> getA() { return _A; }
  inline ulong getLenI() { return _A.size(); }
  inline ulong getLenJ() { return _A[0].size(); }
  std::vector<float> operator[](int index) { return _A[index]; }
  friend Matrix operator+(Matrix m1, Matrix m2) {
    if ((m1.getLenI() != m2.getLenI()) or (m1.getLenJ() != m2.getLenJ()))
      return Matrix();
    auto A = m1.getA();
    for (ulong i = 0; i < m2.getLenI(); i++)
      for (ulong j = 0; j < m2.getLenJ(); j++)
        A[i][j] += m2[i][j];
    return Matrix(A);
  }
  friend Matrix operator-(Matrix m1, Matrix m2) {
    if ((m1.getLenI() != m2.getLenI()) or (m1.getLenJ() != m2.getLenJ()))
      return Matrix();
    auto A = m1.getA();
    for (ulong i = 0; i < m2.getLenI(); i++)
      for (ulong j = 0; j < m2.getLenJ(); j++)
        A[i][j] -= m2[i][j];
    return Matrix(A);
  }
  friend Matrix operator*(Matrix m1, Matrix m2) {
    if (m1.getLenJ() != m2.getLenI())
      return Matrix();
    std::vector<std::vector<float>> A;
    for (ulong i = 0; i < m1.getLenI(); i++) {
      std::vector<float> line;
      for (ulong j = 0; j < m2.getLenJ(); j++) {
        float aij = 0.0;
        for (ulong k = 0; k < m1.getLenJ(); k++)
          aij += m1[i][k] * m2[k][j];
        line.push_back(aij);
      }
      A.push_back(line);
    }
    return Matrix(A);
  }
  void print() {
    for (ulong i = 0; i < getLenI(); i++) {
      for (ulong j = 0; j < getLenJ(); j++)
        printf("%8.3f  ", (*this)[i][j]);
      std::cout << std::endl;
    }
  }

private:
  std::vector<std::vector<float>> _A;
  static bool validation(std::vector<std::vector<float>> A) {
    if (not A.size())
      return false;
    ulong first = A[0].size();
    for (ulong i = 0; i < A.size(); i++)
      if (A[i].size() != first)
        return false;
    return true;
  }
};

#endif // L12CLASSES_H
