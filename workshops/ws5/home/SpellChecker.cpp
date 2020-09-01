#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <regex>
#include "SpellChecker.h"

namespace sdds{
	SpellChecker::SpellChecker(const char* filename){

		std::ifstream file(filename);
		if (!file){
			throw std::invalid_argument("Bad file name!");
		}
		std::string line;
		int cnt = 0;

		do{
			std::getline(file, line);
			if(cnt < 5){
				m_badWords[cnt] = line.substr(0, line.find(' ') - line.find(' '));
			
				line.erase(0, line.find(' '));

				std::string temp = line.substr(line.find_first_not_of(' '), line.find('\n'));
                temp.erase(std::remove(temp.begin(), temp.end(), '\n'));
                temp.erase(std::remove(temp.begin(), temp.end(), '\r'));
                m_goodWords[cnt] = temp;
                
			}
			
			++cnt;
		}while(file);
		file.close();
		
		
	}

	void SpellChecker::operator()(std::string& text) const{
		
		while(text.find(m_badWords[0]) != std::string::npos)
    		text.replace(text.find(m_badWords[0]), m_badWords[0].length(), m_goodWords[0]);

    	while(text.find(m_badWords[1]) != std::string::npos)
    		text.replace(text.find(m_badWords[1]), m_badWords[1].length(), m_goodWords[1]);

    	while(text.find(m_badWords[2]) != std::string::npos)
    		text.replace(text.find(m_badWords[2]), m_badWords[2].length(), m_goodWords[2]);

    	while(text.find(m_badWords[3]) != std::string::npos)
    		text.replace(text.find(m_badWords[3]), m_badWords[3].length(), m_goodWords[3]);

    	while(text.find(m_badWords[4]) != std::string::npos)
    		text.replace(text.find(m_badWords[4]), m_badWords[4].length(), m_goodWords[4]);

	}



}