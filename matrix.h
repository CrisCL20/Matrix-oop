#include <iostream>
#include <math.h>

using namespace std;

class matrix{
    private:
        int rows;
        int cols;
        double** mat;
    public:
        matrix(int rows,int cols);
        ~matrix();
        int getRows();
        int getCols();
        double** getMatrix();
        void setMatrix(double**);
        bool isSquare();
        double det();
        void inverse();
};

matrix* Identity(int);

bool isEven(int);