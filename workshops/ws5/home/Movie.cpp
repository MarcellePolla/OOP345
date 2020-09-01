#include <iostream>
#include <string>
#include <iomanip>
#include "Movie.h"
namespace sdds{

	Movie::Movie(){}

	Movie::Movie(const std::string& strMovie){

		std::string line = strMovie;
		
		m_title = line.substr(line.find_first_not_of(' '), line.find(',') - line.find_first_not_of(' '));
		line.erase(0, line.find(',') + 1);
		m_year = std::stoi(line.substr(line.find_first_not_of(' '), line.find(',') - line.find_first_not_of(' ')));
		line.erase(0, line.find(',') + 1);
		m_description = line.substr(line.find_first_not_of(' '), line.find('\n') - line.find_first_not_of(' '));

	}

	const std::string& Movie::title() const{ return m_title;}

	void Movie::display(std::ostream& os) const{
		os << std::setw(40) << m_title << " | "
		<< std::setw(4) << m_year << " | "
		<< m_description
		<< std::endl;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie){
		 os << std::setw(40) << movie.m_title << " | "
			<< std::setw(4) << movie.m_year << " | "
			<< movie.m_description
			<< std::endl;
		return os;
	}
}