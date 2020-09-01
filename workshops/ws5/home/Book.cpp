#include <iostream>
#include <string>
#include <algorithm> 
#include <cstddef>
#include <iomanip>
#include "Book.h"

namespace sdds{
	//constructors
	Book::Book(){}
	Book::Book(const std::string& strBook){
		
		std::string line = strBook;
		std::string items[5];
		int i = 0;
		size_t pos = 0;

		while(i < 5){
			pos = line.find(',');
			std::string item = line.substr(line.find_first_not_of(' '), pos - line.find_first_not_of(' '));
			
			item.erase(item.find_last_not_of(" \t\n\r\f\v") + 1);

			items[i++] = item;
    		line.erase(0, pos + 1);
		}

		m_author = items[0];
		m_title = items[1];
		m_country = items[2];
		m_price = std::stod(items[3]);
		m_yearPublication = std::stoi(items[4]);
		m_description = line.substr(line.find_first_not_of(' '), line.find('\n') - line.find_first_not_of(' '));
		
	}
	//queries
	const std::string& Book::title() const{ return m_title;}
	const std::string& Book::country() const{return m_country;}
	const size_t& Book::year() const{return m_yearPublication;}
	double& Book::price(){return m_price;}
	//displays
	void Book::display(std::ostream& os) const{
		os << std::setw(20) << m_author << " | "
		<< std::setw(22) << m_title << " | "
		<< std::setw(5) << m_country << " | "
		<< std::setw(4) << m_yearPublication << " | "
		<< std::fixed << std::setw(6) << std::setprecision(2) << m_price << " | "
		<< m_description
		<< std::endl;
	}

	std::ostream& operator<<(std::ostream& os, Book& book){
		os  << std::setw(20) << book.m_author << " | "
			<< std::setw(22) << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_yearPublication << " | "
			<< std::fixed << std::setw(6) << std::setprecision(2) << book.m_price << " | "
			<< book.m_description
			<< std::endl;
		return os;
		
	}


}
