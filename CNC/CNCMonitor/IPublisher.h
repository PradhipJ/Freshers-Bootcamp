#pragma once

class IPublisher {
public:
    virtual void publish() = 0;
    virtual ~IPublisher() {}
};
