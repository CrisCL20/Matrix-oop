#include <iostream>
#include <math.h>

using namespace std;

class matrix{
    private:
        int rows;
        int cols;
        int** mat;
    public:
        matrix(int rows,int cols);
        ~matrix();
        int getRows();
        int getCols();
        int** getMatrix();
        void setMatrix(int**);
        bool isSquare();
        double det();
        void inverse();
};

matrix* Identity(int);

bool isPair(int);