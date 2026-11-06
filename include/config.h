#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

constexpr float WHEEL_DIAMETER = 60.0f;
constexpr int   IMP_PER_ROTATE = 982;
constexpr float WHEEL_WIDTH    = 156.0f; // Колея, мм

constexpr float WHEEL_CIRCUMFERENCE = PI * WHEEL_DIAMETER;
constexpr float MM_PER_IMP          = WHEEL_CIRCUMFERENCE / IMP_PER_ROTATE;

constexpr unsigned long VEL_UPDATE_MS = 20;

#define PIN_R_SENSOR   A3
#define PIN_L_SENSOR   A2

#define PIN_IN1_L       7
#define PIN_IN2_L       8
#define PIN_EN_L        6
#define PIN_ENC_L_A     2
#define PIN_ENC_L_B     4

#define PIN_IN1_R       9
#define PIN_IN2_R      10
#define PIN_EN_R        5
#define PIN_ENC_R_A     3
#define PIN_ENC_R_B    11

struct motor_cfg_t {
    uint8_t pin_in1;
    uint8_t pin_in2;
    uint8_t pin_en;
    uint8_t pin_enc_a;
    uint8_t pin_enc_b;
    bool invert;
};

struct sensor_cfg_t {
    uint8_t pin;
};

struct config_t {
    motor_cfg_t  motor_L;
    motor_cfg_t  motor_R;
    sensor_cfg_t sensor_L;
    sensor_cfg_t sensor_R;
};


#endif