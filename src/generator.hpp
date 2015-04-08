#pragma once

const double srate = 48000.0;
const int buffer_size = 1024;

class Generator
{
  public:
    double samples[buffer_size];

    virtual void start(int offset) = 0;
    virtual int generate() = 0;
};
