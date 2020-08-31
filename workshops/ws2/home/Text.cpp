#include <iostream>
#include <fstream>
#include "Text.h"
namespace sdds{

    int Text::textCt = 0;

    Text::Text():s(nullptr){}

    Text::Text(char* fileName){
        std::ifstream file;
        file.open(fileName);

        if(file.is_open()){
            while(!file.eof()) 
            //checks each character for space
                if(file.get() == 32)
                    textCt++;
        }

        //returns to the beginning of the file to copy
        file.seekg(0);
        s = new std::string[textCt];
        int i = 0;
        std::string store;

        while(std::getline(file, store))
            s[i] = store;
    }
    Text::Text(const Text& t){
        *this = t;
    }
    Text& Text::operator=(const Text& t){
        if(this != &t){
            textCt = t.textCt;
            delete [] s;
            s = new std::string[textCt];

            for(int i = 0; i < textCt; i++){
                s[i] = t.s[i];
            }
        }
        return *this;
    }
    Text::Text(Text&& src){
        *this = std::move(src);
    }
    Text&& Text::operator=(Text&& src){
        if(this != &src){
            s = src.s;
            src.s = nullptr;
        }
        return std::move(*this);
    }

    Text::~Text(){
        delete [] s;
        s = nullptr;
    }
    size_t Text::size() const{
        return textCt;
    }
}