#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdio.h>
#include <fstream>

#define n 10 //n value
#define y0 2 //initial condition

using namespace std;

double f1(double,double);


int main(void)
{

    int a = 1,b = 2; //interval
    double w = y0; //initial condition

    //step 1
    double h = ( (double) b - (double) a) / n;
    double t = a;
    int i = 1;

    ofstream fout ("vis/diffeq.csv");

    if(!fout) cerr << "Could not open file\n";

    fout << scientific;
    fout.precision(8);

    fout << "t" << "," << "y" << endl; 

    //step 2
    
    while(i<=n){
        w = w + h * f1(w,t);
        t = a + i * h;

        fout << t << "," << w << endl;

        i++;

    }


    return 0;

}


double f1(double y,double t){
    return (1+t)/(1+y);
}