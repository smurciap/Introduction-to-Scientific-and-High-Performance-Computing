#include "factorial.h"

int factorial(int number)
{  //problemas adicionales numeros negativos, numeros muuy grandes...
    if(0== number) return 1;
    return number <= 1 ? number : factorial(number-1)*number;
}