#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <exception>
#include <cassert>
#include <cmath>
//#include <armadillo>

using namespace std;

  class Matrix{
    public:
    Matrix();
    Matrix(int rows, int colums);
    void Output();//int rows, int colums, double** matrix);
    int get_rows();
    int get_colums();
    bool eq_matrix(const Matrix& other);
    void Sum_Matrix(const Matrix& other);
    void Sub_Matrix(const Matrix& other);
    void Fill_part(const Matrix& other);
    void Fill_other();
    void Mul_number(const double num);
    void Mul_Matrix(const Matrix& other);
    void Matrix_transpose();
    void Calc_Complemens();
  
    private:
    int rows_, colums_;
    double** matrix;
    double** Matrix_memory(int rows, int colums);//int rows, int colums, double** matrix);
    void Fill();//int rows, int colums, double** matrix);
    //https://arma.sourceforge.net/docs.html
  };
