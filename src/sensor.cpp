#include "sensor.h"

LineSensor::LineSensor(const sensor_cfg_t& cfg)
    : _cfg(cfg) {}

void LineSensor::begin(){
    pinMode(_cfg.pin, INPUT);
}

int LineSensor::read(){
    return map(analogRead(_cfg.pin), 40, 840, 0, 100);
}
