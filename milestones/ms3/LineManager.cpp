#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& filename, std::vector<Task*>& task, std::vector<CustomerOrder>& custOrder){
    /*
     read the records from file and setup all the m_pNextTask references in the Task objects,
     Linking each Task object together to form the assembly line
     Move all the CustomerOrder objects onto the front of the ToBeFilled queue
     Copy all the Task objects into the AssemblyLine container
     */
    std::ifstream file(filename);
    std::string line;
    std::string firstTask;
    std::string nextTask;
    std::vector<std::string> first;
    
    while(std::getline(file, line)){
        std::stringstream strs(line);
        std::getline(strs, firstTask, '|');
        std::getline(strs, nextTask, '\r');
        
        //std::cout << "FT"<<firstTask << "|" << std::endl;
        //std::cout << "NT"<<nextTask << "|" << std::endl;

        first.push_back(firstTask);

        for(size_t i = 0; i < task.size() ; i++)    {
            if(task[i]->getName() == firstTask) {
                if (firstTask != nextTask) {
                    for(size_t j = 0; j < task.size(); j++) {
                        if(task[j]->getName() == nextTask){
                            task[i]->setNextTask(*task[j]);
                            //break;
                        }
                    }
                }
                //break;
            }
        }
        //if(file.eof()) break;
    }

    

        for(size_t i = 0; i < task.size(); i++){
            AssemblyLine.push_back(task[i]);
        }

        std::vector<Task *> sorted;

        for(size_t j = 0; j < first.size(); j++){
        
            for(size_t i = 0; i < AssemblyLine.size(); i++){
                if(AssemblyLine[i]->getName() == first[j]){
                    sorted.push_back(AssemblyLine[i]);
                }
            }

        }

        m_firstTask = sorted.front();
        m_lastTask = sorted.back();

    m_cntCustomerOrder = custOrder.size();
    for (size_t i = 0; i < custOrder.size(); i++){
        ToBeFilled.push_front(std::move(custOrder[i]));
    }
   
}

bool LineManager::run(std::ostream& os) {
    /*
     this function performs one cycle of operations on the assembly line by doing the following:
     If there are any CustomerOrder objects in the ToBeFilled queue,
     move the last CustomerOrder object onto the starting point of the AssemblyLine
     (you have to identify which task is the starting point of your assembly line)
     
     Loop through all tasks on the assembly line and run one cycle of the task's process
     
     Loop through all tasks on the assembly line and move the CustomerOrder objects down the line.
     Hint: completed orders should be moved into the Completed queue.
     return true if all customer orders have been filled, otherwise returns false.
     */
    bool filled = false;
    
 
    if(ToBeFilled.size()){
        (*m_firstTask) += std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
    }


 
    for (size_t i = 0; i < AssemblyLine.size(); i++){
        AssemblyLine[i]->runProcess(os);
        
    }

    for (size_t i = 0; i < AssemblyLine.size(); i++){
        
        CustomerOrder tmpObj;
        if (m_lastTask->getCompleted(tmpObj)) {
            Completed.push_back(std::move(tmpObj));
        }
        AssemblyLine[i]->moveTask();
    }
  
    if (Completed.size() == m_cntCustomerOrder){ filled = true; }
    
    return filled;
}

void LineManager::displayCompleted(std::ostream& os) const {
    //displays all the orders that were completed
    for (size_t i = 0; i < Completed.size(); i++){
        Completed[i].display(os);
    }
}

void LineManager::validateTasks() const {
    //validates each task on the assembly line
    for (size_t i = 0; i < AssemblyLine.size(); i++){
        AssemblyLine[i]->validate(std::cout);
    }  
}
