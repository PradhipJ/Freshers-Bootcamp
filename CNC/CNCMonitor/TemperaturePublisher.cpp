#pragma once
#include "TemperaturePublisher.h"

TemperaturePublisher::TemperaturePublisher(EventAggregator& ea) : eventAggregator(ea), temperature(0.0) {
    eventAggregator.addPublisher(EventType::Temperature, this);
}

void TemperaturePublisher::updateTemperature(double temp) {
    temperature = temp;
}

void TemperaturePublisher::publish() {
        eventAggregator.publish(EventType::Temperature, temperature);
}
