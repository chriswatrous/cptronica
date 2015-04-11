#include "saw.hpp"

Saw::Saw(double freq)
{
    init(freq, -1);
}

Saw::Saw(double freq, double length)
{
    init(freq, length);
}

void Saw::init(double freq, double length)
{
    this->freq = freq;
    this->length = length;
    samples = 0;
    step = 2 * freq / srate;
    value = 0;
    current_sample = 0;
    total_samples = length < 0 ? -1 : length * srate;
}

Generator* Saw::GetGenerator()
{
    return new Saw(freq, length);
}

int Saw::Generate()
{
    if (samples == 0) samples = new double[buffer_size];

    bool ending = total_samples >= 0 && current_sample + buffer_size >= total_samples;

    int length = ending ? total_samples - current_sample : buffer_size;

    for (int i = 0; i < length; i++)
    {
        samples[i] = value;
        value += step;
        if (value > 1) value -= 2;
    }
    current_sample += length;

    return ending ? length : -1;
}

Saw::~Saw()
{
    if (samples) delete samples;
}
