#ifndef UTILS_HPP
#define UTILS_HPP


namespace utils
{
    struct GeneratorRandValueForArray
    {
        GeneratorRandValueForArray(int len, int lim);
        void operator()(int* arr);

        int length;
        int limit;
    };
    int** generate_matrix(int rows, int colms);
    void clear_colms(int* ptr);
    void clear_matrix(int** matrix, int rows);
    void transponce_matrix(int** destination, int** source, int rows, int colms);
}

#endif // UTILS_HPP
