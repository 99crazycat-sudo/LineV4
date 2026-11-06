#ifndef SENSOR_H
#define SENSOR_H
#include "config.h"

class LineSensor {
    public:
        LineSensor(const sensor_cfg_t& cfg);
        void begin();
        int read();
    private:
        const sensor_cfg_t& _cfg;
};

#endif