#include <iostream>
#include <fstream> 

float suma1(int N) {
    float suma = 0.0f;
    for (int n = 1; n <= N; n++) {
        suma += 1.0f / n;
    }
    return suma;
}
float suma2(int N) {
    float suma = 0.0f;
    for (int n = N; n >= 1; n--) {
        suma += 1.0f / n;
    }
    return suma;
}

int main() {
    int valor_deseado= 10000; /* Este es el valor de N de las sumas al que se llegará a evaluar*/
    std::ofstream archivo("tabla_tarea1.txt"); 
    archivo << "Tabla de valores para las funciones 1/n de n= 1 hasta N con su respectivo error relativo:" << std::endl;
    archivo << "N\tSuma 1 \tSuma 2\tDiferencia Relativa de las Sumas" << std::endl;
    for (int N = 1; N <= valor_deseado; N+=1) {
        float S1 = suma1(N);
        float S2 = suma2(N);
        float DiferenciaRelativa = std::abs(1 - S1 / S2);
        archivo << N << "\t" << S1 << "\t\t" << S2 << "\t\t" << DiferenciaRelativa << std::endl;
    }

    archivo.close();
    std::cout << "Se ha creado exitosamente el archivo tabla_tarea1.txt con los respectivos datos. Recuerde graficarlos en Python usando el comando skiprow=2 de matplotlib" << std::endl;
    return 0;
}
