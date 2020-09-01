#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField {0};

Item::Item(){}
Item::Item(const std::string line){

	Utilities util;
	size_t pos = 0;
	bool more = false;

	m_name = util.extractToken(line, pos, more);

	pos = line.find(util.getDelimiter()) + 1;

	m_serialNumber = std::stoi(util.extractToken(line, pos, more));

	pos = line.find(util.getDelimiter(), pos + 1) + 1;

	m_quantity = std::stoi(util.extractToken(line, pos, more));

	pos = line.find(util.getDelimiter(), pos + 1) + 1;

	m_description = util.extractToken(line, pos, more);

	if(m_widthField < m_name.length()) m_widthField = m_name.length();

}

const std::string& Item::getName() const{ return m_name;}

const unsigned int Item::getSerialNumber(){ return m_serialNumber++;}

const unsigned int Item::getQuantity(){ return m_quantity;}

void Item::updateQuantity(){ if(m_quantity > 0) m_quantity -= 1;}

void Item::display(std::ostream& os, bool full) const{
	os << std::left << std::setw(m_widthField) << m_name 
		<< " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << std::setfill(' ') << "]";
	if(full){
		os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity << " Description: " << m_description; 
	}
	os << std::endl;
}