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

void cofactor(matrix* mymat, double** temp, int p, int q){
    
    //get cofactor (stoled from https://www.geeksforgeeks.org/adjoint-inverse-matrix/)
    if(!mymat->isSquare()) cerr << "Matrix is not square!\n";

    const int n = mymat->getRows();

    double** mat = mymat->getMatrix();

    int z=0,k=0;

    for(int r = 0;r < n;r++){
        for(int c = 0;c<n;c++){ //kekw
            if(r != p && c != q){
                temp[z][k++] = mymat->getMatrix()[r][c];

                if(k == n-1) 
                    k = 0, z++;
            }
        }
    }
}

void matrix::adjoint(){
    if(!this->isSquare()) cerr << "Matrix is not square!\n";
    const int n = this->rows;

    double** adj = new double* [n];
    for(int i = 0;i<n;i++) adj[i] = new double[n];

    matrix* temp = new matrix(this->rows,this->cols);
    if(n == 1){ 
        adj[0][0] = 1;
        return;
    }

    int s = 1;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cofactor(this,temp->mat,i,j);
            s = ((i+j)%2 == 0) ? 1 : -1;
            adj[j][i] = s * temp->det();
        }
    }


}

void matrix::inverse(){
    if(!this->isSquare()) 
        cerr << "Matrix is not square!\n";
    
    if(this->det() == 0) 
        cerr << "Determinant is zero!\n";
    
    const int n = this->rows;

    matrix* identity = Identity(n);
    const double det = this->det();


   
}