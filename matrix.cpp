#include "matrix.h"

bool isPair(int n){
    if(n%2==0) return 1;
    return 0;
}


matrix::matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;

    this->mat = new int*[this->rows];
    for(int i = 0;i<this->rows;i++) this->mat[i] = new int [this->cols];
}



matrix::~matrix(){delete[] this->mat;}

int matrix::getRows(){
    return this->rows;
}

int matrix::getCols(){
    return this->cols;
}

int** matrix::getMatrix(){
    return this->mat;
}

void matrix::setMatrix(int** matrix){
    this->mat = matrix;
}

bool matrix::isSquare(){
    return (this->rows == this->cols) ? 1 : 0;
}

matrix* Identity(int N){
    matrix* iden = new matrix(N,N);

    int** identity = new int* [N];
    for(int i=0;i<N;i++) identity[i] = new int[N];

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
    
    int** modifiable = this->mat;
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

    matrix* identity = Identity(n);
    const double determinant = this->det();



}