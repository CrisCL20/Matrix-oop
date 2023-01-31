#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <fstream>


#define n 100 //n value
#define m 2 //Number of ode's 
#define y10 0 //initial condition for f1
#define y20 0 //initial cond for f2

using namespace std;

double f1(double,double,double);
double f2(double,double,double);

int main(void)
{

    int a = 0,b = M_PI; //interval
    double w_1 = y10, w_2 = y20,dt;

    //step 1
    double h = ( (double) b - (double) a) / n;
    double t = a;

    double k1[m+1], k2[m+1], k3[m+1], k4[m+1]; //m+1 so we can index from 1 to m

    ofstream fout ("vis/diffeq.csv");

    if(!fout) cerr << "Could not open file\n";

    fout << scientific;
    fout.precision(5);

    fout << "t" << "," << "y" << "," << "w" << endl;
    fout << t << "," << w_1 << "," << w_2 << endl;

    for(int i = 1;i <= n;i++){
        
        k1[1] = h * f1(w_1,w_2,t);
        k1[2] = h * f2(w_1,w_2,t);

        k2[1] = h * f1(w_1 + (k1[1] / 2),w_2 + (k1[2] / 2),t + (h / 2) );
        k2[2] = h * f2(w_1 + (k1[1] / 2),w_2 + (k1[2] / 2),t + (h / 2) );

        k3[1] = h * f1(w_1 + (k2[1] / 2),w_2 + (k2[2] / 2),t + (h / 2) );
        k3[2] = h * f2(w_1 + (k2[1] / 2),w_2 + (k2[2] / 2),t + (h / 2) );

        k4[1] = h * f1(w_1 + k3[1],w_2 + k3[2],t + h );
        k4[2] = h * f2(w_1 + k3[1],w_2 + k3[2],t + h );

        w_1 = w_1 + (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1])/6;
        w_2 = w_2 + (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2])/6;

        t = a + i*h;

        fout << t << "," << w_1 << "," << w_2 << endl;
    }
    


    return 0;

}


double f1(double y1,double y2,double t){
    return 6 - 4 * y1 + 3 * y2;
}

double f2(double y1, double y2, double t){
    return 3.6 - 2.4 * y1 + 1.6 * y2;
}