#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include "SongCollection.h"
namespace sdds{

	SongCollection::SongCollection(const char* filename){
		std::ifstream file(filename);
		if (!file){
			//TODO: throw exception
			throw std::invalid_argument ("ERROR: Cannot open file.");
			return;
		}
		
		while (file)
        {
        	std::string strFile;
            std::getline(file, strFile);

        	if(strFile.length() > 0){
				Song s;

				s.m_title = trim(strFile.substr(0, 25));

				strFile.erase(0, 25);

				s.m_artist = trim(strFile.substr(0, 25));

				strFile.erase(0, 25);

				s.m_album = trim(strFile.substr(0, 25));

				strFile.erase(0, 25);

				s.m_year  = trim(strFile.substr(0, 5));

				strFile.erase(0, 5);

				s.m_length = trim(strFile.substr(0, 5));

				strFile.erase(0, 5);
				
				s.m_price = trim(strFile.substr(0, 5));
				
				//std::cout << "|" << s.m_title << "|" << s.m_artist << "|" << s.m_album << "|" << s.m_year << "|" << s.m_length << "|" << s.m_price << "|" <<std::endl;

				m_songs.push_back(s);

        	}

        }

        file.close();
	}

	std::string SongCollection::trim(std::string str){		
		if (!std::all_of(str.begin(),str.end(),isspace))
			str = str.substr(str.find_first_not_of(' '), (str.find_last_not_of(' ') - str.find_first_not_of(' ')) + 1);
		else
			str = "";
		return  str; 	
	}

	void SongCollection::display(std::ostream& out) const{
		std::for_each(m_songs.begin() , m_songs.end() , [&out](auto x){out << x <<std::endl;});
	/*	
		for(auto i = m_songs.begin(); i != m_songs.end(); i++){
				out << (*i) <<std::endl;
			}
	*/
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong){
		int length = stoi(theSong.m_length);
		int minutes = length /60;
		int seconds = length - (minutes * 60);

		out << "| " << std::setw(20) << std::left <<  theSong.m_title
		<< " | " << std::setw(15) << theSong.m_artist 
		<< " | " << std::setw(20) << theSong.m_album
		<<std::right
		<< " | " << std::setw(6) << theSong.m_year
		<< " | " << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << std::setfill(' ')
		<< " | " << theSong.m_price << " |";
		return out;
	}




}