#pragma once
#include<unordered_map>
#include<vector>
#include "IPublisher.h"
#include "ISubscriber.h"

using namespace std;

class EventAggregator
{
private:
	unordered_map<EventType, vector<ISubscriber*>> subscribers;
	unordered_map<EventType, IPublisher*> publishers;
public:
	void subscribe(EventType eventType, ISubscriber* subscriber);
	void addPublisher(EventType eventType, IPublisher* publisher);
	void publish(EventType eventType, double value);
	void publishAll();
};

