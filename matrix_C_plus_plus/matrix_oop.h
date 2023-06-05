#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <cmath>

class S21Matrix {
private:
    int _rows, _cols;                                           // rows and columns attributes
    double **_p;                                                // pointer to the memory where the matrix will be allocated

private:
    void matrix_allocate();


public:
    S21Matrix();                                                // default constructor
    S21Matrix(int rows, int cols);                              // parameterized constructor
    S21Matrix(const S21Matrix& o);                              // copy cnstructor
    S21Matrix(S21Matrix&& o);                                   // move cnstructor
    ~S21Matrix();                                               // destructor

    // some operators overloads
    S21Matrix& operator=(const S21Matrix& o);                   // assignment operator overload
    double& operator()(int row, int col);                          // index operator overload
    double& operator()(int row, int col) const;
    S21Matrix& operator+=(const S21Matrix& o);                            
    S21Matrix operator+(const S21Matrix& o);
    S21Matrix& operator-=(const S21Matrix& o);
    S21Matrix operator-(const S21Matrix& o);
    bool operator==(const S21Matrix& o);
    S21Matrix operator*(const double num);
    S21Matrix operator*(const S21Matrix& o);
    S21Matrix& operator*=(const double num);
    S21Matrix& operator*=(const S21Matrix& o);
    
    // some public methods
    bool EqMatrix(const S21Matrix& o);
    void SumMatrix(const S21Matrix& o); 
    void SubMatrix(const S21Matrix& o);
    void MulNumber(const double num); 
    void MulMatrix(const S21Matrix& o);
    S21Matrix Transpose();
    S21Matrix Minor(const int i, const int j);
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();
    void fill_matrix();

};

#endif
