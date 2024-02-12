#pragma once
#include "EventAggregator.h"

void EventAggregator::subscribe(EventType eventType, ISubscriber* subscriber) {
    subscribers[eventType].push_back(subscriber);
}

void EventAggregator::addPublisher(EventType eventType, IPublisher* publisher) {
    publishers[eventType] = publisher;
}

void EventAggregator::publish(EventType eventType, double value) {
    for (ISubscriber* subscriber : subscribers[eventType]) {
        subscriber->onEvent(eventType, value);
    }
}

void EventAggregator::publishAll() {
    for (auto& entry : publishers) {
        entry.second->publish();
    }
}


