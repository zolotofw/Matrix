#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix matrix(5, 5);
    Matrix matrix2(5, 5);
    matrix.set_rand_values(5);
    matrix2.set_rand_values(5);
    matrix.transponce();
    Matrix addition_matrix(std::move(matrix + matrix2));
    Matrix multi_matrix(std::move(matrix * matrix2));
    Matrix substract_matrix(std::move(matrix - matrix2));



    return 0;
}
