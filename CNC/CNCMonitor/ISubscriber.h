#pragma once
#include "Events.h"

class ISubscriber {
public:
    virtual void onEvent(EventType eventType, double value) = 0;
    virtual ~ISubscriber() {}
};