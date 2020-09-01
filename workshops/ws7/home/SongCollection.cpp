#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list> 
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

				try{
					s.m_year  = std::stoi(trim(strFile.substr(0, 5)));
				}catch(...){
					s.m_year = 0;
				}
				strFile.erase(0, 5);

				s.m_length = std::stoi(trim(strFile.substr(0, 5)));
				strFile.erase(0, 5);
				
				s.m_price = std::stod(trim(strFile.substr(0, 5)));
			
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

	void SongCollection::sort(std::string field){
		if(field == "title"){
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& begin, const Song& end) {return begin.m_title < end.m_title;});
		}
		else if(field == "length"){
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& begin, const Song& end) {return begin.m_length < end.m_length;});
		}
		else if(field == "album"){
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& begin, const Song& end) {return begin.m_album < end.m_album;});
		}
	}

	void SongCollection::cleanAlbum(){
		std::for_each(m_songs.begin() , m_songs.end() , [](Song& s){if(s.m_album == "[None]") s.m_album = "";});
	}

	bool SongCollection::inCollection(std::string artist) const{
		auto search = std::find_if(m_songs.begin() , m_songs.end(), [&artist](const Song& song){ return song.m_artist == artist;} );
		return search != m_songs.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const{
		
		std::list<Song> songList;
		std::for_each(m_songs.begin() , m_songs.end() ,[&artist, &songList](const Song& s){if(s.m_artist == artist) songList.push_back(s);});
		return songList;
	}

	void SongCollection::display(std::ostream& out) const{
		std::for_each(m_songs.begin() , m_songs.end() , [&out](const Song& x){out << x <<std::endl;});

		int totalTime = 0;

		std::for_each(m_songs.begin() , m_songs.end() , [&totalTime](const Song& song){totalTime+=song.m_length;});

		int hours = totalTime / 3600;
		int minutes = (totalTime %= 3600) / 60;
		int seconds = totalTime %  60;

		out << "----------------------------------------------------------------------------------------\n"
		 	<< "|                                                        Total Listening Time: " 
		 	<< hours << ":" << minutes << ":" << seconds <<" |" 
		 	<< std::endl;
			
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong){
		int length = theSong.m_length;
		int minutes = length /60;
		int seconds = length - (minutes * 60);

		out << "| " << std::setw(20) << std::left <<  theSong.m_title
			<< " | " << std::setw(15) << theSong.m_artist 
			<< " | " << std::setw(20) << theSong.m_album
			<<std::right;
		if(theSong.m_year == 0)
			out << " | " << std::setw(6) << "";
		else
			out << " | " << std::setw(6) << theSong.m_year;
		out << " | " << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << std::setfill(' ')
			<< " | " << theSong.m_price << " |";
		return out;
	}




}