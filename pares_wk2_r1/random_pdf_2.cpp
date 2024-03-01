//============================================================================
// Name        : random_pdf.cpp
// Author      : Johan Alejandro López Arias
// Description : Este programa calcula y muestra la función de densidad de probabilidad (PDF) para diferentes semillas de una distribución normal dada
                //, generando un histograma de frecuencias relativas. Se requiere la entrada de seis parámetros: número de muestras, media (mu), 
                // desviación estándar (sigma), mínimo y máximo del rango de valores, y número de contenedores (bins) para el histograma. Utiliza un 
                // generador de números pseudoaleatorios para simular muestras de una distribución normal y distribuye estas muestras en un histograma 
                // para calcular la PDF. Los resultados se imprimen en formato CSV, incluyendo el centro de cada bin y los valores de la PDF para cada 
                // semilla utilizada. 

                //La función `main` verifica la entrada de los seis parámetros requeridos. Si no se ingresan correctamente, el programa terminará, 
                // mostrando un mensaje de error. Si se ingresan correctamente, se inicializan las variables con los valores de los parámetros y se 
                // procede a calcular la PDF para cada semilla usando la función `compute_pdf`. Esta función genera las muestras, las clasifica en bins,
                // y calcula la PDF para cada bin, almacenando los resultados para su posterior impresión. Finalmente, el programa imprime el resultado
                // en formato CSV, listando los centros de los bins y los valores de la PDF correspondientes a cada semilla.

                //PD: Las tres seeds ya se encuentran por defecto en el codigo de manera que no se piden como entrada.
//============================================================================
#include <random>	// Incluye la cabecera que proporciona funcionalidades para la generación de números pseudoaleatorios.
#include <iostream>	// Incluye la cabecera de la biblioteca de entrada/salida para operaciones de entrada/salida.
#include <cstdlib>	// Incluye la cabecera de la biblioteca estándar general de utilidades, incluyendo conversiones de strings a números.
#include <vector>	// Incluye la cabecera para el contenedor de vector de la biblioteca estándar.
#include <iomanip> // Para manipular el formato de salida

// Declara la función para calcular la función de densidad de probabilidad (pdf) de una distribución normal.
void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins, std::vector<std::vector<double>>& results, std::vector<double>& bin_centers, int seedIndex);

int main(int argc, char **argv) // Punto de entrada principal del programa, donde comienza la ejecución.
{

    // Verifica si el número de argumentos es igual a 7 (nombre del programa + 6 parámetros).
    //Tambien advierte de como debe ser la entrada por consola
    if (argc != 7) {
        std::cerr << "Error: Debes ingresar 6 parametros de entrada.\nSe recomienda que sean: 5000 3.5 0.4 2.7 4.6 50.\nLas seeds 1,2 y 5 se ejecutan por defecto, no es necesario ingresarlas.";
        return 1; // Termina la ejecución con un código de error.
    }

    const int NSAMPLES = std::atoi(argv[1]);// Convierte el segundo argumento de la línea de comandos a entero para el número de muestras.
    const double MU = std::atof(argv[2]);// Convierte el tercer argumento de la línea de comandos a double para la media de la distribución
    const double SIGMA = std::atof(argv[3]);// Convierte el cuarto argumento de la línea de comandos a double para la desviación estándar de la distribución.
    const double XMIN = std::atof(argv[4]);// Convierte el quinto argumento de la línea de comandos a double para el mínimo del rango de valores.
    const double XMAX = std::atof(argv[5]);// Convierte el sexto argumento de la línea de comandos a double para el máximo del rango de valores.
    const int NBINS = std::atoi(argv[6]);// Convierte el séptimo argumento de la línea de comandos a entero para el número de contenedores (bins) en el histograma.
    
    int seeds[] = {1, 2, 5}; // Define un array con las semillas a utilizar para la generación de números aleatorios.
    
    std::vector<std::vector<double>> results(NBINS, std::vector<double>(3)); // Inicializa una matriz para almacenar los resultados de las PDFs para cada semilla.
    std::vector<double> bin_centers; // Vector para almacenar los centros de los bins.
    for(int i = 0; i < 3; ++i) {
        // Pasa el vector de centros de los bins como argumento a compute_pdf.
        compute_pdf(seeds[i], NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS, results, bin_centers, i);
    }

    // Imprime la cabecera con las semillas y 'bin_center' en el formato CSV.
    std::cout << "bin_center";
    for(int seed : seeds) {
        std::cout << ";" << seed;
    }
    std::cout << std::endl;

    // Imprime cada bin, su centro y los resultados en formato CSV.
    for(int i = 0; i < NBINS; ++i) {
        std::cout << bin_centers[i]; // Imprime el centro del bin.
        for(int j = 0; j < 3; ++j) {
            std::cout << ";" << results[i][j]; // Imprime los resultados de la PDF.
        }
        std::cout << std::endl;
    }
    std::cout << "\nSe ha impreso en formato .csv por lo que el codigo debe copiarse y guardarse como un archivo .csv para visualizar su grafica en excel";
    return 0;
}

// Añade un parámetro para el vector de centros de los bins
void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins, std::vector<std::vector<double>>& results, std::vector<double>& bin_centers, int seedIndex)
{
    std::mt19937 gen(seed); // Generador de números pseudoaleatorios.
    std::normal_distribution<double> dis(mu, sigma); // Distribución normal.

    std::vector<int> histogram(nbins, 0); // Histograma inicializado a cero.
    double bin_width = (xmax - xmin) / nbins; // Ancho de cada bin.

    // Calcula los centros de los bins solo si es la primera vez (seedIndex == 0).
    if(seedIndex == 0) {
        bin_centers.resize(nbins); // Asegúrate de que el vector tiene el tamaño correcto.
        for(int i = 0; i < nbins; ++i) {
            bin_centers[i] = xmin + bin_width * (i + 0.5); // Calcula el centro de cada bin.
        }
    }

    for(int n = 0; n < nsamples; ++n) {
        double r = dis(gen); // Genera un número aleatorio.
        if(r >= xmin && r < xmax) {
            int bin_index = static_cast<int>((r - xmin) / bin_width); // Encuentra el índice del bin.
            histogram[bin_index]++; // Incrementa el histograma.
        }
    }

    for(int i = 0; i < nbins; ++i) {
        results[i][seedIndex] = (double)histogram[i] / (nsamples * bin_width); // Calcula la PDF.
    }
}