#include "Utils.hpp"
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>


namespace utils
{
    GeneratorRandValueForArray::GeneratorRandValueForArray(int len, int lim)
        :
          length(len),
          limit(lim)
    {
        srand(time(NULL));
    }

    void GeneratorRandValueForArray::operator()(int* arr)
    {
        int lim = limit;
        std::generate(arr, arr + length,
                      [lim]()
                      {
                        return rand() % lim;
        });
    }

    void clear_colms(int* ptr)
    {
        delete[] ptr;
    }

    void clear_matrix(int** matrix, int rows)
    {
        std::for_each(matrix, matrix + rows, clear_colms);

        delete[] matrix;
    }

    int** generate_matrix(int rows, int colms)
    {
        int** temp_matrix = new int*[rows];
        std::generate(temp_matrix, temp_matrix + rows,
                  [colms]()
                  {
                    return new int[colms];
                  });

        return temp_matrix;
    }

    void transponce_matrix(int** destination, int** source, int rows, int colms)
    {
        for(int row = 0; row < colms; ++row)
        {
            for(int colm = 0; colm < rows; ++colm)
            {
                destination[row][colm] = source[colm][row];
            }
        }
    }

}
