#ifndef MOVIE_H
#define MOVIE_H
#include "SpellChecker.h"
namespace sdds{
	class Movie{
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		void display(std::ostream& os) const;
		template<typename T>
		void fixSpelling(T spellChecker){
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif