#pragma once

#include "generator.hpp"

class MulConst : public Generator
{
  private:
    Generator *input;
    double amount;
    
  public:
    MulConst(GeneratorDef *input, double amount);
    ~MulConst();
    virtual int Generate();
    virtual Generator* GetGenerator();
};
