#ifndef SDDS_STRING_H__
#define SDDS_STRING_H__
#include <iostream>

namespace sdds
{
    extern unsigned int g_maxSize;
    class String {
        char* _str;
        public:
        String(const char*);
        ~String();
        String(const String&);
        String& operator=(const String&);
        void display(std::ostream&) const;    
    };
    std::ostream& operator<<(std::ostream&, const String&);
}
#endif