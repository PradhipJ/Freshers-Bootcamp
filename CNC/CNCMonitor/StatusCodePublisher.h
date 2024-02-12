#pragma once
#include "EventAggregator.h"
class StatusCodePublisher : public IPublisher {
private:
    EventAggregator& eventAggregator;
    int statusCode;
public:
    StatusCodePublisher(EventAggregator& ea);
    void updateStatusCode(int code);
    void publish();
};

