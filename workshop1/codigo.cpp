#include <iostream>
#include <cmath>
#include <vector>

// Suma desde 1 hasta N
float sum1(int N){
    float sum = 0;
    for (float k=1; k<N+1; k++){
        sum += 1/k;
    }
    return sum;
}

// Suma desde N hasta 1
float sum2(int N){
    float sum = 0;
    for (float k=N; k>0; k--){
        sum += 1/k;
    }
    return sum;
}

int main(){

    // de border[i] a border[i+1] se varía N en pasos de spacing[i]
    std::vector<float> borders = {1e4, 1e6, 1e7};
    std::vector<float> spacing = {1e2, 1e3, 1e4};

    int N = 0;
    // Recorrer los vectores
    for (int ind=0; ind<borders.size(); ind++){
        // Usar spacing[i] en ese intervalo
        while (N<borders[ind]){
            N += spacing[ind];
            float S1 = sum1(N);
            float S2 = sum2(N);
            float Delta = fabs( 1 - S1/S2 );
            
            std::cout<< N <<"\t"<< S1 <<"\t"<< S2 <<"\t"<< Delta << std::endl;
        }
    }

    return 0;
}