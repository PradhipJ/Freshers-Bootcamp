#pragma once
#include "EventAggregator.h"
#include <atomic>

class ContinuousOperationPublisher : public IPublisher {
private:
    EventAggregator& eventAggregator;
    std::atomic<int> duration;
public:
    ContinuousOperationPublisher(EventAggregator& ea);
    void updateDuration(int dur);
    void publish();
};