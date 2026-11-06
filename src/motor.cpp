#include "motor.h"

Motor_t::Motor_t(motor_cfg_t &conf)
    : _conf(conf),
      _speed(0.0f) {}


bool Motor_t::Init(){
    pinMode(_conf.pin_in1, OUTPUT); 
    pinMode(_conf.pin_in2, OUTPUT); 
    pinMode(_conf.pin_en, OUTPUT); 
    return true;
}

void Motor_t::SetSpeed(float speed){
    _speed = speed;
}

void Motor_t::Stop(){
    _speed = 0.0f;
}

void Motor_t::Update(){
    float s = fabsf(_speed);
    if (s > 255.0f) {
        s = 255.0f;
    }

    bool dir = (_speed >= 0.0f) != _conf.invert;

    if (dir) {
        digitalWrite(_conf.pin_in1, LOW);
        digitalWrite(_conf.pin_in2, HIGH);
    } else {
        digitalWrite(_conf.pin_in1, HIGH);
        digitalWrite(_conf.pin_in2, LOW);
    }

    analogWrite(_conf.pin_en, (uint8_t)s);
}