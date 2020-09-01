#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <vector>

namespace sdds{
	struct Song{
		std::string m_title;
		std::string m_artist;
		std::string m_album;
		double m_price;
		int m_year;
		int m_length;
	};

	class SongCollection{
		std::vector<sdds::Song> m_songs;
	public:
		SongCollection(const char* file);
		void display(std::ostream& out) const;
		std::string trim(std::string);
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif