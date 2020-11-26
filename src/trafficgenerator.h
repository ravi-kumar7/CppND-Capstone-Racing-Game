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
        TrafficGenerator(int screen_width, int screen_height);
        std::deque<std::shared_ptr<Vehicle>> vehicles;
        void GenerateVehicle();

    private:
        std::shared_ptr<Vehicle> _truck;
        std::shared_ptr<Vehicle> _van;
        std::shared_ptr<Vehicle> _taxi;
        std::shared_ptr<Vehicle> _car;
        std::random_device _rd;
        std::mt19937 _rng;
        std::uniform_int_distribution<int> _vehicle_dist;
        std::uniform_int_distribution<int> _pos_dist;
        bool loaded = false;
        std::chrono::time_point<std::chrono::system_clock> _lastVehicleTime;
        float _delay;

};

#endif