#pragma once
#include "ContinuousOperationPublisher.h"

ContinuousOperationPublisher::ContinuousOperationPublisher(EventAggregator& ea) : eventAggregator(ea), duration(0) {
    eventAggregator.addPublisher(EventType::ContinuousOperation, this);
}

void ContinuousOperationPublisher::updateDuration(int dur) {
    duration = dur;
}

void ContinuousOperationPublisher::publish(){
    eventAggregator.publish(EventType::ContinuousOperation, duration);
}
