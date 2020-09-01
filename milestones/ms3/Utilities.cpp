#include <iostream>
#include <string>
#include "Utilities.h"

char Utilities::m_delimiter;

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){

	std::string token = " ";

	token = str.substr(next_pos, str.find(m_delimiter ,next_pos) - next_pos);
	

	if(token.length()){
		more = true;
	} 
	else {
		more = false;
		throw "No token";
	}

	if(getFieldWidth() < token.length()) setFieldWidth(token.length());

	return rtrim(token);
}

void Utilities::setFieldWidth(size_t width){ m_widthField = width;}

size_t Utilities::getFieldWidth() const {return m_widthField;}

void Utilities::setDelimiter(const char c) { m_delimiter = c;}

const char Utilities::getDelimiter() const { return m_delimiter;}

std::string& Utilities::rtrim(std::string& str) {
    size_t endpos = str.find_last_not_of("\r\n\t");
    if(endpos != std::string::npos) {
        str.substr(0,endpos+1).swap(str);
    }
    return str;
}
