#include <stdio.h>
#include <math.h>

#include "generator.hpp"
#include "saw.hpp"
#include "mulconst.hpp"

double p2f(double pitch);

int main()
{
    Generator *gen = new MulConst(new Saw(p2f(55), 1), 0.25);
    gen->Play();

    return 0;
}


double p2f(double pitch)
{
    return 440*pow(2, (pitch - 69)/12);
}
