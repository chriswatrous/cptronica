#pragma once

#include "generatordef.hpp"

const double srate = 48000.0;
const int buffer_size = 1024;

class Generator : public GeneratorDef
{
  public:
    double *samples;

    virtual int Generate() = 0;

    void Play();

  private:
    void put_samples(int length);
};
