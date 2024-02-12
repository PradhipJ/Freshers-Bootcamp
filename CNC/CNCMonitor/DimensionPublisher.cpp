#pragma once
#include "DimensionPublisher.h"

DimensionPublisher::DimensionPublisher(EventAggregator& ea) : eventAggregator(ea), dimension(0.0) {
    eventAggregator.addPublisher(EventType::Dimension, this);
}

void DimensionPublisher::updateDimension(double dim) {
    dimension = dim;
}

void DimensionPublisher::publish() {
    eventAggregator.publish(EventType::Dimension, dimension);
}