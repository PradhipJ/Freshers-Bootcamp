#pragma once
#include "EventAggregator.h"
#include <atomic>

class TemperaturePublisher : public IPublisher {
private:
    EventAggregator& eventAggregator;
    std::atomic<double> temperature;
public:
    TemperaturePublisher(EventAggregator& ea);
    void updateTemperature(double temp);
    void publish() override;
};