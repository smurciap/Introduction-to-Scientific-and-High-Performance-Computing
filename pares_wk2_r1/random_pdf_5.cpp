#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char** argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
  return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis(mu, sigma);
  // TODO: histogram stuff
  std::vector <double> histogram(nbins, 0);
  double delta = (xmax-xmin)/nbins;

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    int position = (r-xmin)/delta;
    // TODO: fill here the counting histogram stuff
    if (r>=xmin && r<=xmax){histogram[position]++;}
  }
  
  std::ofstream outputFile("histograma_"+std::to_string(seed) +".txt");
  for(int jj = 0; jj < nbins; jj++){
    outputFile<<histogram[jj]<<std::endl;
  }
  outputFile.close();
  // TODO: compute and print the pdf
  std::cout<<"x"<<std::setw(10)<<"P(x)"<<std::endl;
  for(int ii=0; ii<=nbins; ii++){
    std::cout<<xmin+ii*delta<<std::setw(10)<<histogram[ii]/5000.0<<std::endl;
  }
  
}
