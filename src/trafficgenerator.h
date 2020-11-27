#ifndef TRAFFIC_GENERATOR_H
#define TRAFFIC_GENERATOR_H

#include <iostream>
#include <chrono>
#include <deque>
#include <memory>
#include <random>
#include "vehicle.h"

class TrafficGenerator{
    public:
        TrafficGenerator(int screen_width, int screen_height, long delay);
        std::deque<std::shared_ptr<Vehicle>> vehicles;
        void GenerateVehicle();

    private:
        int screen_width;
        int screen_height;
        std::random_device _rd;
        std::mt19937 _rng;
        std::uniform_int_distribution<int> _vehicle_dist;
        std::uniform_int_distribution<int> _pos_dist;
        bool loaded = false;
        std::chrono::time_point<std::chrono::system_clock> _lastVehicleTime;
        long _delay;

};

#endif