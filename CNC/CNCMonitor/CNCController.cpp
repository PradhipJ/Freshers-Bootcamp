#include "CNCController.h"

void CNCController::onEvent(EventType eventType, double value){
    switch (eventType) {
    case EventType::Temperature:
        cout << "Temperature Event: " << value << endl;
        if (value > 35.0) {
            cout << "Alert: Temperature exceeds 35 degrees Celsius!" << endl;
        }
        break;
    case EventType::Dimension:
        cout << "Dimension Event: " << value << endl;
        if (value > 0.05) {
            cout << "Alert: Part dimension variation exceeds 0.05 mm!" << endl;
        }
        break;
    case EventType::StatusCode:
        cout << "Status Code Event: " << value << endl;
        break;
    case EventType::ContinuousOperation:
        cout << "Continuous Operation Event: " << value << " minutes" << endl;
        if (value > 360) {
            cout << "Alert: Continuous operation exceeds 6 hours!" << endl;
        }
        break;
    default:
        cerr << "Unknown event type!" << endl;
    }
}



