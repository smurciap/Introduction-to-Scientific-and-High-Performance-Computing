#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::stod(argv[3]);
  const double SIGMA = std::stod(argv[4]);
  const double XMIN = std::stod(argv[5]);
  const double XMAX = std::stod(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);

  return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  // Definición del vector que cuenta y del intervalo de cada bin
  std::vector<int> hst(nbins);
  double range = (xmax-xmin)/(double)nbins;

  // Se declara un for en el que los númeroa aleatorios se asignan a la variable r

  

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);

    // Se resta el mínimo para obtener la distancia desde allí
    // Y se divide entre el rango acotando el número a entero para obtener el bin en el que se encuentra
    int where = (r-xmin)/range;

    // Se va aumentando el contador
    if (where >=0 && where < nbins){
      hst[where] = hst[where]+1;
    }

  }

  //std::ofstream outfile;
  //outfile.open("random_pdf.txt");

  // El número de cuentas se le asigna al punto medio de cada bin
  double meanv = xmin + range/2;

  for(int i = 0; i < nbins; i++) {
    std::cout << meanv << " " << hst[i]/(nsamples*range) << std::endl;
    //outfile << meanv << " " << hst[i]/(nsamples*range) << std::endl;
    meanv = meanv+range;
  }
  //outfile.close();

}