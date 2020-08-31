#include <iostream>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"
namespace sdds{

    size_t TimedEvents::storedRecords = 0;

    TimedEvents::TimedEvents(){

    }
    void TimedEvents::startClock(){
        startTime = std::chrono::steady_clock::now();
    }
    void TimedEvents::stopClock(){
        endTime = std::chrono::steady_clock::now();
    }
    void TimedEvents::recordEvent(const char* name){
        auto start = startTime;
        auto end = endTime;
        if(name && storedRecords < MAX_RECORDS){
            records[storedRecords].eventName = name;
            records[storedRecords].unitsOfTime  = "nanoseconds";
            records[storedRecords].eventDuration = end - start;
            storedRecords++;
        }
    }

    void TimedEvents::display(std::ostream& os){
        for(int i = 0; i < (int)storedRecords; i++){
            os << std::setw(20) << left << records[i].eventName  
            << std::setw(12) << right << std::chrono::duration_cast<std::chrono::nanoseconds>(records[i].eventDuration).count() 
            << " " << records[i].unitsOfTime << std::endl;
        }
    }
    std::ostream& operator<<(std::ostream& os, TimedEvents& event){
        os << "--------------------------\nExecution Times:\n--------------------------\n";
        event.display(os);
        os << "--------------------------\n";
        return os;
    }
}