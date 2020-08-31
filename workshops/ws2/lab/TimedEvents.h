#ifndef TIMEDEVENTS_H__
#define TIMEDEVENTS_H__
#include <iostream>
#include <chrono>
using namespace std;

namespace sdds{
    const int MAX_RECORDS = 7;

    class TimedEvents{

        static size_t storedRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;
        struct {
            const char* eventName;
            const char* unitsOfTime;
            std::chrono::steady_clock::duration eventDuration;
        } records[MAX_RECORDS];
        public:
            TimedEvents();
            void startClock();
            void stopClock();
            void recordEvent(const char* name);
            void display(std::ostream& os);
    };

    std::ostream& operator<<(std::ostream& os, TimedEvents& event);

}
#endif