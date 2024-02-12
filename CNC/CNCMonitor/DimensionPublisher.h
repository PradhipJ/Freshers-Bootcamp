#pragma once
#include "EventAggregator.h"

class DimensionPublisher : public IPublisher {
private:
    EventAggregator& eventAggregator;
    double dimension;
public:
    DimensionPublisher(EventAggregator& ea);
    void updateDimension(double dim);
    void publish();
};
