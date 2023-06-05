#include "matrix_oop.h"

S21Matrix::S21Matrix() {
    _rows = 3;
    _cols = 3;
    matrix_allocate();
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    if (_rows <= 0 || _cols <= 0) {
        throw std::out_of_range("rgffd");
    }
    matrix_allocate();
}

S21Matrix::S21Matrix(const S21Matrix& o) : _rows(o._rows), _cols(o._cols) {
    matrix_allocate();
    *this = o;
    
}

S21Matrix::S21Matrix(S21Matrix&& o) : _rows(0), _cols(0), _p(nullptr) {
    std::swap(_rows, o._rows);
    std::swap(_cols, o._cols);
    std::swap(_p, o._p);
}

S21Matrix::~S21Matrix() {
    if (_p) {
        for (int i = 0; i < _rows; i++) {
            delete[] _p[i];
        }
        delete[] _p;
    }
}

void S21Matrix::SumMatrix(const S21Matrix& o) {
    if (_rows != o._rows || _cols != o._cols) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows; i++) {
        for (auto j = 0; j < _cols; j++) {
            _p[i][j] = _p[i][j] + o._p[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& o) {
    if (_rows != o._rows || _cols != o._cols) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows; i++) {
        for (auto j = 0; j < _cols; j++) {
            _p[i][j] = _p[i][j] - o._p[i][j];
        }
    }
}

bool S21Matrix::EqMatrix(const S21Matrix& o) {
    bool f = true;
    if (_rows != o._rows || _cols != o._cols) {
        f = false;
    }
    if (f == true) {
        for (auto i = 0; i < _rows; i++) {
            for (auto j = 0; j < _cols; j++) {
                if (fabs(_p[i][j] - o._p[i][j]) > 1E-7) {
                    f = false;
                    break;
                }
            }
        }
    }
    return f;
}

void S21Matrix::MulNumber(const double num) {
    for (auto i = 0; i < _rows; i++) {
        for (auto j = 0; j < _cols; j++) {
            _p[i][j] = _p[i][j] * num;
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& o) {
    if (_cols != o._rows) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    S21Matrix res(_rows, o._cols);
    for (auto i = 0; i < _rows; i++) {
        for (auto j = 0; j < o._cols; j++) {
            for (auto k = 0; k < _cols; k++) {
                res._p[i][j] += _p[i][k]*o._p[k][j];
            }
        }
    }
    *this = res;
}

S21Matrix S21Matrix::Transpose() {
    S21Matrix res(_cols, _rows);
    for (auto i = 0; i < _rows; i++) {
        for (auto j = 0; j < _cols; j++) {
            res._p[j][i] = _p[i][j];
        }
    }
    return res;
}

S21Matrix S21Matrix::Minor(const int i, const int j) {
    S21Matrix res(_rows-1, _cols-1);
    for (auto ii = 0; ii < _rows - 1; ii++) {
        for (auto jj = 0; jj < _cols - 1; jj++) {
            if (ii < i && jj < j)
                    res._p[ii][jj] = _p[ii][jj];
            if (ii < i && jj >= j)
                    res._p[ii][jj] = _p[ii][jj+1];
            if (ii >= i && jj < j)
                    res._p[ii][jj] = _p[ii+1][jj];
            if (ii >= i && jj >= j)
                    res._p[ii][jj] = _p[ii+1][jj+1];
        }
    }
    return res;
}

double S21Matrix::Determinant() {
    if (_rows != _cols) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    double res = 0;
    if (_rows == 1) {
        res = _p[0][0];
    } else if (_rows == 2) {
        res = _p[0][0]*_p[1][1] - _p[0][1]*_p[1][0];
    } else {
        // std::cout << "ddd" "\n\n\n";
        for (auto i = 0; i < _cols; i++) {
            S21Matrix minor = Minor(0, i);
            res += _p[0][i] * minor.Determinant()*pow(-1, i);
            // std::cout << "str" << minor.Determinant() << "\n\n\n";
        }
    }
    return res;
}

S21Matrix S21Matrix::CalcComplements() {
    if (_rows != _cols && _cols < 1) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    S21Matrix res(_rows, _cols);
    if (_rows == 1) {
        res._p[0][0] = _p[0][0];
    } else if ( _rows > 1) {
        for (auto i = 0; i < _rows; i++) {
            for (auto j = 0; j < _cols; j++) {
                S21Matrix minor = Minor(i, j);
                res._p[i][j] = pow(-1, i+j)*minor.Determinant();
            }
        }
    }
    return res;
}

S21Matrix S21Matrix::InverseMatrix() {
    if (_rows != _cols) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    double D = Determinant();
    if (D == 0) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    S21Matrix calccomp = CalcComplements();
    S21Matrix transposecalc = calccomp.Transpose();
    transposecalc.MulNumber(1/D);
    return transposecalc;
}







// operator overload example
S21Matrix S21Matrix::operator+(const S21Matrix& o) {
    // creating result matrix
    S21Matrix res(*this);
    res.SumMatrix(o);
    return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
    S21Matrix res(*this);
    res.SubMatrix(o);
    return res;
}

bool S21Matrix::operator==(const S21Matrix& o) {
    S21Matrix res(*this);
    bool r = res.EqMatrix(o);
    return r;
}

S21Matrix S21Matrix::operator*(const double num) {
    // creating result matrix
    S21Matrix res(*this);
    res.MulNumber(num);
    return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
    // creating result matrix
    S21Matrix res(*this);
    res.MulMatrix(o);
    return res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
    SumMatrix(o);
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
    SubMatrix(o);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
    MulNumber(num);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
    MulMatrix(o);
    return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
    // освободить память
    _rows = o._rows;
    _cols = o._cols;
    // выделить память
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _p[i][j] = o._p[i][j];
        }
    }
    return *this;
}





// index operator overload
double& S21Matrix::operator()(int row, int col) {
    if (row >= _rows || col >= _cols) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return _p[row][col];
}

void S21Matrix::matrix_allocate() {
    _p = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _p[i] = new double[_cols];
    }
    for (auto i = 0; i < _rows; i++) {
        for (auto j = 0; j < _rows; j++) {
            _p[i][j] = 0;
        }
    }
}

void S21Matrix::fill_matrix() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _p[i][j] = i + j;
        }
    }
}