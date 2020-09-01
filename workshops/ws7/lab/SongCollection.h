#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <vector>

namespace sdds{
	struct Song{
		std::string m_title;
		std::string m_artist;
		std::string m_album;
		std::string m_price;
		std::string m_year;
		std::string m_length;
	};

	class SongCollection{
		std::vector<Song> m_songs;
	public:
		SongCollection(const char* file);
		void display(std::ostream& out) const;
		std::string trim(std::string);
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif