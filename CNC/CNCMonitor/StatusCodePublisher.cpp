#include "StatusCodePublisher.h"

StatusCodePublisher::StatusCodePublisher(EventAggregator& ea) : eventAggregator(ea), statusCode(0) {
    eventAggregator.addPublisher(EventType::StatusCode, this);
}

void StatusCodePublisher::updateStatusCode(int code) {
    statusCode = code;
}

void StatusCodePublisher::publish() {
    eventAggregator.publish(EventType::StatusCode, statusCode);
}
