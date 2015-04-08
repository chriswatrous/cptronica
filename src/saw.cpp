#include "saw.hpp"

Saw::Saw(double freq, double length)
{
    start_offset = -1;
    step = 2 * freq / srate;
    value = 0;
    total_samples = length * srate;
}

void Saw::start(int offset)
{
    start_offset = offset;
}

int Saw::generate()
{
    for (int i = 0; i < buffer_size; i++)
    {
        samples[i] = value;
        value += step;
        if (value > 1) value -= 2;
    }
    return -1;
}
