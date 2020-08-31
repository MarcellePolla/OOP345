#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;
namespace sdds
{
    unsigned int g_maxSize = 3;
    String::String(const String& source){
        _str = nullptr;
        *this = source;
    }

    String::String(const char* name){
        if(name != nullptr){
           _str = new char[ g_maxSize];
            strncpy(_str, name, g_maxSize);
        }else{
            _str = nullptr;
        }
    }

    String& String::operator=(const String& source){
        if(this != &source){
           delete [] _str;
            if(source._str != nullptr){
                _str = new char[g_maxSize];
                strncpy(_str, source._str, g_maxSize);
            }else
                _str = nullptr;
        }
        return *this;
    }

    String::~String(){
        delete [] _str;
        _str = nullptr;
    }
    void String::display(std::ostream& os) const{
        os << _str;
    }
    std::ostream& operator<<(std::ostream& os, const String& name){
        static int n = 1;
        os << n++ << ": "; 
        name.display(os);
        return os;
    }
}