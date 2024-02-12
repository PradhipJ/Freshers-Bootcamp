#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "TemperaturePublisher.h"
#include "DimensionPublisher.h"
#include "ContinuousOperationPublisher.h"
#include "StatusCodePublisher.h"
#include "CNCController.h"

int main() {
    EventAggregator eventAggregator;

    TemperaturePublisher temperaturePublisher(eventAggregator);
    DimensionPublisher dimensionPublisher(eventAggregator);
    StatusCodePublisher statusCodePublisher(eventAggregator);
    ContinuousOperationPublisher continuousOperationPublisher(eventAggregator);

    CNCController cncController;

    eventAggregator.subscribe(EventType::Temperature, &cncController);
    eventAggregator.subscribe(EventType::Dimension, &cncController);
    eventAggregator.subscribe(EventType::StatusCode, &cncController);
    eventAggregator.subscribe(EventType::ContinuousOperation, &cncController);

    std::thread tempThread([&] {
        while (true) {
            temperaturePublisher.updateTemperature(36.0);
            temperaturePublisher.publish();
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        });

    std::thread contOpThread([&] {
        while (true) {
            continuousOperationPublisher.updateDuration(400);
            continuousOperationPublisher.publish();
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        });

    dimensionPublisher.updateDimension(0.06);
    dimensionPublisher.publish();

    statusCodePublisher.updateStatusCode(0);
    statusCodePublisher.publish();

    tempThread.join();
    contOpThread.join();

    return 0;
}
