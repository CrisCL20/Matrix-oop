#include "matrix.h"

bool isEven(int n){
    return (n%2 == 0) ? 1:0;
}


matrix::matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;

    this->mat = new double* [this->rows];
    for(int i = 0;i<this->rows;i++) this->mat[i] = new double [this->cols];
}



matrix::~matrix(){delete[] this;}

int matrix::getRows(){
    return this->rows;
}

int matrix::getCols(){
    return this->cols;
}

double** matrix::getMatrix(){
    return this->mat;
}

void matrix::setMatrix(double** matrix){
    this->mat = matrix;
}

bool matrix::isSquare(){
    return (this->rows == this->cols) ? 1 : 0;
}

matrix* Identity(int N){
    matrix* iden = new matrix(N,N);

    double** identity = new double* [N];
    for(int i=0;i<N;i++) identity[i] = new double[N];

    for(int i=0;i<N;i++)
    for(int j = 0;j<N;j++)
    (i == j) ? identity[i][j] = 1 : identity[i][j] = 0;
    
    iden->setMatrix(identity);

    return iden;
    
}

double matrix::det(){
    if(!this->isSquare())
        cerr << "Matrix is not square!\n";
    
    const int n = this->rows;
    
    double** modifiable = this->mat;
    int n1,n2,index;
    
    double total=1,det=1;

    int* temp = new int[n+1];

    for (int i = 0;i < n;i++){
        index = i;

        while ( index < n && modifiable[index][i] == 0 ) index++;

        if(index == n) continue;
        if(index != i)
        {
            for(int j=0;j<n;j++) std::swap(modifiable[index][j],modifiable[i][j]);

            det = det * std::pow(-1,index-i);
        }
        for(int j=0;j<n;j++) temp[j] = modifiable[i][j];
        for(int j=i+1;j<n;j++){
            n1 = temp[i];
            n2 = modifiable[j][i];

            for(int k = 0;k<n;k++)
                modifiable[j][k] = 
                    (n1 * modifiable[j][k]) - (n2 * temp[k]);
            
            total = total * n1;
        }
    }

    for(int i=0;i<n;i++)
    det = det * modifiable[i][i];

    return det / total;

}

void matrix::inverse(){
    if(!this->isSquare()) 
        cerr << "Matrix is not square!\n";
    
    if(this->det() == 0) 
        cerr << "Determinant is zero!\n";
    
    //Do this using Gauss - Jordan!

    const int n = this->rows;
    int diag;
    matrix* identity = Identity(n);
    const double determinant = this->det();

    for (int i = 0;i < n; i++){
        
        diag = this->mat[i][i]; //multiply whole row by this element
        
        for(int j=0;j<n;j++)
            this->mat[i][j] = this->mat[i][j] * diag,
            identity->mat[i][j] = identity->mat[i][j] * diag; //what we do to A we have to do to I
    }

    //now A has 1's on its diagonals and other numbers anywhere else
    // I have to make it so we get to zero everywhere else but the diagonals!

}