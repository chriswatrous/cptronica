#pragma once

#include "generator.hpp"

class Saw : public Generator
{
  private:
    int start_offset;
    double value;
    double step;
    int total_samples;

  public:
    Saw(double freq, double length);
    virtual void start(int offset);
    virtual int generate();
};
