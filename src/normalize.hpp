#pragma once

#include "generator.hpp"

class Normalize : public Generator
{
  public:
    Normalize(Generator *gen);
    int generate();

  private:
    vector<double> all_samples;
}
