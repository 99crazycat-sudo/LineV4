#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "config.h"

class Encoder_t {
public:
    Encoder_t(const motor_cfg_t& cfg);
    void begin();
    long  count();
    void  handleInterupt();  

private:
    const motor_cfg_t& _cfg;
    volatile long _count;
};

#endif