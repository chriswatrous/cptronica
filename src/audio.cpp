#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <vector>

#include "generator.hpp"
#include "saw.hpp"

//using namespace std;

void put_samples(double *samples, int num);

int main()
{
    Saw saw (440, 2);



    while (1)
    {
        saw.generate();
        put_samples(saw.samples, buffer_size);
    }

    return 0;
}

void put_samples(double *samples, int num)
{
    for (int i = 0; i < num; i++)
    {
        double sample = samples[i];
        if (sample > 1) sample = 1;
        if (sample < -1) sample = -1;

        unsigned short output_sample = (samples[i] + 1) / 2 * 0xFFFF;

        putchar(output_sample & 0xFF);
        putchar(output_sample >> 8);
    }
}

double p2f(double pitch)
{
    return 440*pow(2, (pitch - 69)/12);
}
