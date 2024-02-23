#include <iostream>

float S_1(int N);

float S_2(int N);

float Error(float a, float b);

int main(int argc, char ** argv)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  
  for(int ii = 1; ii < 1e6; ++ii)
    {
      std::cout << ii << "\t" << S_1(ii) << "\t" << S_2(ii) << "\t" << Error(S_1(ii), S_2(ii)) << "\n";
    }
  return 0;
}

float S_1(int N)
{
  float sum = 0.0;
  for(int ii = 1; ii <= N; ++ii)
    {
      sum += 1.0/ii;
    }
  return sum;
}

float S_2(int N)
{
  float sum = 0.0;
  for(int ii = 0; ii < N; ++ii)
    {
      sum += 1.0/(N - ii);
    }
  return sum;
}

float Error(float a, float b)
{
  return std::abs(1.0 - a/b);
}
