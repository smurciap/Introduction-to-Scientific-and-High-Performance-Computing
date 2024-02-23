#include<iostream>
#include<cmath>

float suma1(float N){
    float resultado=0;
    for(float i=1;i<=N;i++){
        resultado+=(1/i);       
    }
    return resultado;
}

float suma2(float N){
    float resultado=0;
    for(float i=N;i>=1;i--){
        resultado+=1/i;
    }
    return resultado;
}

float diferencia_realtiva(float x1, float x2){
    return std::abs(1.0-(x1/x2));
}

int main(){
    float S1,S2;
    for (float N=0;N<=1e6;N+=100){
        if (N==0){continue;}               
        S1=suma1(N);
        S2=suma2(N);
        std::cout<<N<<" "<<S1<<" "<<S2<<" "<<diferencia_realtiva(S1,S2)<<std::endl;
    }
}