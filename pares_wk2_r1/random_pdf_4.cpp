#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>

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

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // TODO: histogram stuff

  std::cout << "x,y\n";

  std::vector<int> contenedor(nbins, 0);
  
  for(int n = 0; n < nsamples; ++n)
    {
      double r = dis(gen);
      if((r < xmax) && (r > xmin))
	{
	  contenedor[nbins*(r - xmin)/(xmax - xmin)] += 1;
	}
    }
  
  double h = (xmax - xmin)/nbins;

  // TODO: compute and print the pdf
  
  for(int ii = 0; ii < nbins; ii++)
    {
      std::cout << xmin + h*(ii + 0.5) << "," << contenedor[ii]/(double)nsamples << "\n";
    }
}
