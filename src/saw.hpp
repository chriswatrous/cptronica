#pragma once

#include "generator.hpp"
#include "generatordef.hpp"

class Saw: public Generator
{
  private:
    double freq;
    double length;
    double value;
    double step;
    long total_samples;
    long current_sample;

    void init(double freq, double length);

  public:
    Saw(double freq);
    Saw(double freq, double length);
    ~Saw();
    virtual int Generate();
    virtual Generator* GetGenerator();
};

