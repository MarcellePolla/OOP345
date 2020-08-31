#ifndef TEXT_H__
#define TEXT_H__

#include <string>

namespace sdds{
    class Text{
        static int textCt;
        std::string* s;
        public:
            Text();
            Text(char* fileName);
            Text(const Text&);
            Text& operator=(const Text&);
            ~Text();
            size_t size() const;
    };
}

#endif