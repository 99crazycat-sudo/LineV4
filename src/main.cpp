#include <Arduino.h>
#include "motor.h"
#include "sensor.h"
#include "config.h"
#include "encoder.h"

// Задаём в переменную типа motor_cfg_t пины и инвернсию.
static motor_cfg_t cfg_L = {
    PIN_IN1_L, PIN_IN2_L, PIN_EN_L,
    PIN_ENC_L_A, PIN_ENC_L_B,
    true
};

static motor_cfg_t cfg_R = {
    PIN_IN1_R, PIN_IN2_R, PIN_EN_R,
    PIN_ENC_R_A, PIN_ENC_R_B,
    false
};

static sensor_cfg_t cfg_sL = { PIN_L_SENSOR };
static sensor_cfg_t cfg_sR = { PIN_R_SENSOR };

// Создаём объекты
Motor_t MotorL(cfg_L);
Motor_t MotorR(cfg_R);

LineSensor SensorL(cfg_sL);
LineSensor SensorR(cfg_sR);

Encoder_t EncoderL(cfg_L);
Encoder_t EncoderR(cfg_R);

const int GOAL_SPEED = 80;

void isrEncoderL() { EncoderL.handleInterupt(); }
void isrEncoderR() { EncoderR.handleInterupt(); }

void setup() {
    Serial.begin(115200);

    MotorL.Init();
    MotorR.Init();

    attachInterrupt(digitalPinToInterrupt(PIN_ENC_L_A), isrEncoderL, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_R_A), isrEncoderR, RISING);

    SensorL.begin();
    SensorR.begin();

    EncoderL.begin();
    EncoderR.begin();
    MotorL.SetSpeed(150);
    MotorR.SetSpeed(150);
}

void Line(void){
    int er = SensorL.read() - SensorR.read();
    MotorL.SetSpeed(GOAL_SPEED - er);
    MotorR.SetSpeed(GOAL_SPEED + er);
}

void loop() {
    // int SensorDataL = SensorL.read();
    // int SensorDataR = SensorR.read();

    // Serial.print("SensorDataL = "); Serial.print(SensorDataL); Serial.print(" SensorDataR = "); Serial.println(SensorDataR);



    Serial.print("R = "); Serial.print(EncoderR.count() * MM_PER_IMP); Serial.print("\tL = "); Serial.println(EncoderL.count() * MM_PER_IMP);
    // Line();
    MotorL.Update();
    MotorR.Update();

    //delay(10);
}