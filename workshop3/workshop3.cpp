#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);

int main (int argc, char **argv){
  int ii, jj;
  ii= 0;
  jj= -1;
  foo(ii, jj);
  foo(jj, ii);
  baz(25.9);
    return EXIT_SUCCESS;
}

int foo(int a, int b){

  int divA=(a!=0)?(b/a):0; 
  int divB=(b!=0)?(a/b):0; 
  return divB + b/bar(a, b) + divA;
}

int bar(int a, int b)
{
  unsigned int c = a;
  return c+a-b;
}

double baz(double x)
{
if (x == 0){  
  return 0;   
}
//double v = 1-(x+1); 
return std::sqrt(x);
}