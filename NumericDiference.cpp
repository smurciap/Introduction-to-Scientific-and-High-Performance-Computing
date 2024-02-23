#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

float Sum1(int N);
float Sum2(int N);

int main(void){

    std::ofstream file("Summations.txt");
    file << "N" << "," << "S1" << "," << "S2" << "," << "relDifer" << std::endl;
    for (int N=1; N<=1000000; N+=100){
        float S1=Sum1(N);
        float S2=Sum2(N);

        float relDifer = std::abs(1.0f-(S1/S2));
        std::cout <<N << "," << S1 << "," << S2 << "," << relDifer << std::endl;
    
        file << N << "," << S1 << "," << S2 << "," << relDifer << std::endl;
    }
    file.close();

    return 0;
}

float Sum1(int N){
    float sum = 0.0f;
    for (int k =1; k<=N; ++k){
        sum += 1.0f/k;
    }
    return sum; 
}

float Sum2(int N){
    float sum = 0.0f;
    for (int k =N; k>=1; --k){
        sum += 1.0f/k;
    }
    return sum; 
}
