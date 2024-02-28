#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA , XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // TODO: histogram stuff
  std::vector<int> hgma(nbins, 0); // vector que contiene el conteo del histograma.
  double itval=(xmax-xmin)/static_cast<double>(nbins); // tamaño del intervalo.


  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    
  
    // TODO: fill here the counting histogram stuff
    if(r>=xmin && r<=xmax){
      double i= (r-xmin)/itval; 
      hgma[static_cast<int>(i)]++;
    }
  }

  // TODO: compute and print the pdf
  double area= static_cast<double>(nsamples)*itval;
  for (double j=0.0; j < nbins; ++j){
    double centros= xmin+(j*itval)+(itval/2.0); // centros de los intervalos 
    double pdf=( static_cast<double>(hgma[j])/nsamples); // normalizacion de cada frecuencia utilizando el area 
    std::cout<<centros<<"\t"<<pdf<<std::endl;  
  }
  
}
