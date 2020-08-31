
#ifndef SDDS_STRING_H__
#define SDDS_STRING_H__
#include <iostream>

namespace sdds
{
    extern unsigned int g_maxSize;
    class String {
        char _str[4];
        public:
        String(const char*);
        void display(std::ostream&) const;    
    };
    std::ostream& operator<<(std::ostream&, const String&);
}
#endif