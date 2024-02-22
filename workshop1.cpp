#include <iostream>
#include <list>
#include <iterator> 
#include <cmath>
#include <fstream>

using namespace std;

int N = 1000000;

std::list<double> s1, s2, dlt, i, iter; 

std::list<double> suma() {
    double sum=0.0, frac;
        for (int n = 1; n <= N; ++n) {
            frac = 1.0 / n;
            sum += frac;
       s1.push_back(sum);
    }
    return s1;
}

std::list<double> amus() {
    double sum=0.0, frac;
        for (int n = N; n > 0; --n) {
            frac = 1.0 / n;
            sum += frac;
            s2.push_back(sum);    
    }
    return s2;
}

std::list<double> itera() {
        double sum=0.0;
        for (int n = 1; n <= N; ++n) {
            iter.push_back(n);    
    }
    return iter;
}

std::list<double> delta() {
    s1=suma();   
    s2=amus();
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (; it1 != s1.end() && it2 != s2.end(); ++it1, ++it2) {
            dlt.push_back(fabs(1-(*it1 / *it2)));
    }
    return dlt;
}


int main() {
    s1=suma();
    s2=amus();
    i= itera();
    dlt= delta();
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    auto it3 = i.begin();
    auto it4 = dlt.begin();

    ofstream datafile("datos.txt");
    for (int i = 0; i < N; ++i) {
        datafile << *it3 << "\t\t"  << *it1 << "\t\t" << *it2 <<"\t\t"<< *it4 << endl;
        ++it3;
        ++it1;
        ++it2;
        ++it4;
    }
    datafile.close();


    return 0;
}
