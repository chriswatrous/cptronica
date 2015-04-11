#pragma once

class Generator;

class GeneratorDef
{
  public:
    virtual Generator* GetGenerator() = 0;
};
