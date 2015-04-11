#include "mulconst.hpp"

MulConst::MulConst(GeneratorDef *input, double amount)
{
    this->input = input->GetGenerator();
    this->amount = amount;
}

Generator* MulConst::GetGenerator()
{
    return new MulConst(input, amount);
}

int MulConst::Generate()
{
    if (samples == 0) samples = new double[buffer_size];

    int end_offset = input->Generate();
    double *in = input->samples;
    double *out = samples;
    double *out_end = out + buffer_size;
    while (out < out_end)
    {
        *out = *in * amount;
        in++;
        out++;
    }
    return end_offset;
}

MulConst::~MulConst()
{
    if (samples) delete samples;
    delete input;
}
