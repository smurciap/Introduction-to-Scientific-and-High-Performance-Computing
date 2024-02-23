#include <iostream>
#include <list>
#include <iterator> 
#include <cmath>
#include <fstream>

int N = 10;

float suma(int N);
float amus(int N);

int main(void) {
    std::ofstream datafile("datos.txt");

    for (int i = 1; i < N; ++i) {
        float it2=suma(i);
        float it3=amus(i); 
        float it4=fabs(1.0-(it2 / it3));

        datafile<< i << "\t\t"  << it2 << "\t\t" << it3  <<"\t\t"<< it4<<"\n";
    }
    datafile.close();
    return 0;
}


float suma(int N) {
    double sum=0.0;
        for (int n = 1; n <= N; ++n) {
            sum += 1.0/n;
    } 
    return sum;
}

float amus(int N) {
    double sum=0.0;
        for (int n = N; n >=1 ; --n) {
            sum += 1.0 / n;   
    }
    return sum;
}

