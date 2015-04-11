#include <stdio.h>

#include "generator.hpp"

void Generator::Play()
{
    int end_samples;

    do
    {
        end_samples = Generate();

        int length = end_samples < 0 ? buffer_size : end_samples;

        for (int i = 0; i < length; i++)
        {
            double sample = samples[i];

            if (sample > 1) sample = 1;
            if (sample < -1) sample = -1;

            short output_sample = sample * 0x7FFF;

            putchar(output_sample & 0xFF);
            putchar((output_sample >> 8) & 0xFF);
        }
    } while (end_samples < 0);
}
