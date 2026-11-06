#include "encoder.h"

Encoder_t::Encoder_t(const motor_cfg_t& cfg)
    : _cfg(cfg), _count(0) {}

void Encoder_t::begin(){
    pinMode(_cfg.pin_enc_a, INPUT_PULLUP);
    pinMode(_cfg.pin_enc_b, INPUT_PULLUP);
}

long Encoder_t::count(){
    noInterrupts();
    long c = _count;
    interrupts();
    return _cfg.invert ? - c: c;
}

void Encoder_t::handleInterupt() {
    if (digitalRead(_cfg.pin_enc_b) == HIGH) {
        _count++;
    } else {
        _count--;
    }
}