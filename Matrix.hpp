#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include <iostream>



class Matrix
{
public:
    Matrix();
    Matrix(int rows, int colms);
    Matrix(Matrix&& temp);
    ~Matrix();

    void print_values();
    void transponce();
    void set_rand_values(int limit);
    std::vector<long> sum_rows();
    std::vector<long> sum_colms();
    Matrix operator+(const Matrix& antother);
    Matrix operator*(const Matrix& antother);
    Matrix operator-(const Matrix& antother);


private:
    int m_rows;
    int m_colms;
    int** m_matrix;
};

#endif // MATRIX_HPP
