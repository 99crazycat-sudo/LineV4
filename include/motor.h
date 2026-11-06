#ifndef MOTOR_H
#define MOTOR_H

#include "config.h"

class Motor_t{
    public:
        Motor_t(motor_cfg_t &conf);
        bool Init(void);

        void SetSpeed(float speed);

        void Stop(void);

        void Update(void);
    private:
        motor_cfg_t& _conf;
        float _speed;
};

#endif 