#include "Matrix.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include "TimeTracker.hpp"


Matrix::Matrix()
    :
    m_matrix(nullptr)
{

}

Matrix::Matrix(Matrix&& temp)
    :
      m_rows(temp.m_rows),
      m_colms(temp.m_colms),
      m_matrix(temp.m_matrix)
{
    temp.m_matrix = nullptr;
}

Matrix::Matrix(int rows, int colms)
    :
      m_rows(rows),
      m_colms(colms)
{
    TimeTracker timer(__FUNCTION__);
    m_matrix = utils::generate_matrix(m_rows, m_colms);
}

Matrix::~Matrix()
{
    if(m_matrix != nullptr)
    {
        TimeTracker timer(__FUNCTION__);
        utils::clear_matrix(m_matrix, m_rows);
    }
}

void Matrix::print_values()
{
    TimeTracker timer(__FUNCTION__);
    int length = m_colms;
    std::for_each(m_matrix, m_matrix + m_rows,
                  [length](int* arr)
                  {
                     std::copy(arr, arr + length, std::ostream_iterator<int>{std::cout, " "});
                     std::cout << std::endl;
                  });

}

void Matrix::transponce()
{
    TimeTracker timer(__FUNCTION__);
    int new_rows = m_colms;
    int new_colms = m_rows;
    int **temp_matrix = utils::generate_matrix(new_rows, new_colms);

    utils::transponce_matrix(temp_matrix, m_matrix, m_rows, m_colms);
    utils::clear_matrix(m_matrix, m_rows);

    m_matrix = temp_matrix;
    m_rows = new_rows;
    m_colms = new_colms;
}

void Matrix::set_rand_values(int limit)
{
   TimeTracker timer(__FUNCTION__);
   utils::GeneratorRandValueForArray generator{m_colms, limit};
   std::for_each(m_matrix, m_matrix + m_rows, generator);
}


std::vector<long> Matrix::sum_rows()
{
    TimeTracker timer(__FUNCTION__);
    int colms = m_colms;
    std::vector<long> sum_by_rows;
    std::for_each(m_matrix, m_matrix + m_rows,
                  [&sum_by_rows, colms](int* row)
                  {
                       long sum = std::accumulate(row, row + colms, 0);
                       sum_by_rows.push_back(sum);
                  });

    return sum_by_rows;
}

std::vector<long> Matrix::sum_colms()
{
    TimeTracker timer(__FUNCTION__);
    int colms = m_colms;
    std::vector<long> sum_by_colms;

    for(int colm = 0; colm < m_colms; ++colm)
    {
        long sum = 0;

        for(int row = 0; row < m_rows; ++row)
        {
            sum += m_matrix[row][colm];
        }

        sum_by_colms.push_back(sum);
    }

    return sum_by_colms;
}

Matrix Matrix::operator+(const Matrix &another)
{
    TimeTracker timer(__FUNCTION__);
    if(m_colms != another.m_colms || m_rows != another.m_rows)
    {
        return {};
    }

      Matrix temp(m_rows, another.m_colms);

      for(int row = 0; row < m_rows; ++row)
      {
          for(int colm = 0; colm < m_colms; ++colm)
          {
              temp.m_matrix[row][colm] = m_matrix[row][colm] + another.m_matrix[row][colm];
          }
      }

      return temp;
}

Matrix Matrix::operator*(const Matrix& another)
{
    TimeTracker timer(__FUNCTION__);
    if(m_colms != another.m_rows)
    {
        return {};
    }

    Matrix temp(m_rows, another.m_colms);

    for(int row_1 = 0; row_1 < m_rows; ++row_1)
    {
        for(int colm_2 = 0; colm_2 < another.m_colms; ++colm_2)
        {
            for(int iter = 0; iter < another.m_rows; ++iter)
            {
               temp.m_matrix[row_1][colm_2] += m_matrix[row_1][iter] * another.m_matrix[iter][colm_2];
            }
        }
    }

    return temp;
}

Matrix Matrix::operator-(const Matrix &another)
{
    TimeTracker timer(__FUNCTION__);
    if(m_colms != another.m_colms || m_rows != another.m_rows)
    {
        return {};
    }

      Matrix temp(m_rows, another.m_colms);

      for(int row = 0; row < m_rows; ++row)
      {
          for(int colm = 0; colm < m_colms; ++colm)
          {
              temp.m_matrix[row][colm] = m_matrix[row][colm] - another.m_matrix[row][colm];
          }
      }

      return temp;
}
