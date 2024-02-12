#pragma once
#include <iostream>
#include "EventAggregator.h"
using namespace std;
class CNCController : public ISubscriber {
public:
    void onEvent(EventType eventType, double value);
};


