
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;
namespace sdds
{
    unsigned int g_maxSize = 3;

    String::String(const char* name){
        if(name == nullptr){
            _str[0] = '\0';
        }else{
            strncpy(_str, name, 3);
        }
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