#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <exception>
#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField {0};

CustomerOrder::CustomerOrder(){}

CustomerOrder::CustomerOrder(std::string line){

/*
std::string m_name;
std::string m_product;
unsigned int m_cntItem;
ItemInfo** m_lstItem; 		//array of dinamically allocated of objs ItemInfo
static size_t m_widthField;
*/


//Elliott C.|Gaming PC|CPU|Memory|GPU|GPU|GPU|SSD|Power Supply  --- m_cntItem = 7

	Utilities util;
	size_t pos = 0;
	bool more = false;

	m_name = util.extractToken(line, pos, more);

	pos = line.find(util.getDelimiter()) + 1;

	m_product = util.extractToken(line, pos, more);

	m_cntItem = std::count(line.begin(), line.end(), util.getDelimiter()) - 1;

	m_lstItem = new ItemInfo*[m_cntItem];

	if(m_cntItem >=1){
		for(int i = 0; i < m_cntItem; i++){
		pos = line.find(util.getDelimiter(), pos + 1) + 1;
		m_lstItem[i] = new ItemInfo(util.extractToken(line, pos, more));
		//std::cout << (*m_lstItem[i]).m_itemName << std::endl;
		if(m_widthField < (*m_lstItem[i]).m_itemName.length()) m_widthField = (*m_lstItem[i]).m_itemName.length();
		
		}
	}

	if(m_widthField < util.getFieldWidth()) m_widthField = util.getFieldWidth();


	//std::cout << m_name << std::endl;
	//std::cout << m_product << std::endl;
	//std::cout << m_cntItem << std::endl;
}

CustomerOrder::CustomerOrder(CustomerOrder&){
//The copy constructor should throw an exception if called 
	throw "copy constructor can't be used";
}

CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept{ //This constructor promises that it doesn't throw exceptions. 
	*this = std::move(other);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other){ 
	if (this != &other)
		{
			m_name = other.m_name;
			m_product = other.m_product;


			for (auto i = 0u; i < m_cntItem; ++i){
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			m_cntItem = other.m_cntItem;
			m_lstItem = other.m_lstItem;

			other.m_name = "";
			other.m_product = "";
			other.m_lstItem = nullptr;
		}
		return *this;
}

CustomerOrder::~CustomerOrder(){
	//for (auto i = 0u; i < m_cntItem; ++i){
	//	delete m_lstItem[i];
	//}
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string itemName) const{ 
/*
returns the ItemInfo::m_fillState of the item specified as a parameter. 
If the item doesn't exist in the order, return true
*/
	bool fill = true;
	for (auto i = 0u; i < m_cntItem; ++i){
		if((*m_lstItem[i]).m_itemName == itemName){
			 return fill = (*m_lstItem[i]).m_fillState;
		}
	}

	return fill;
}

bool CustomerOrder::getOrderFillState() const{
/*
	returns true if all the items in the order have been filled; false otherwise
*/	
	bool fill = false;
	for (auto i = 0u; i < m_cntItem; ++i){
		if(!(*m_lstItem[i]).m_fillState){
			return false;
		}
	}

	return fill;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os){
/*
	fills the item in the current order that corresponds to the item passed into the function 
	(the parameter item represents what is available in the inventory).
	if item cannot be found in the current order, this function does nothing
	if item is found, and the inventory contains at least one element, 
	then this function substracts 1 from the inventory 
	and updates ItemInfo::m_serialNumber and ItemInfo::m_fillState. 
	Also it prints the message Filled NAME, PRODUCT[ITEM_NAME].
	if item is found, and the inventory is empty, 
	then this function prints the message Unable to fill NAME, PRODUCT[ITEM_NAME].
	all messages printed should be terminated by an endline
*/
	for (auto i = 0u; i < m_cntItem; ++i){
		if((*m_lstItem[i]).m_itemName == item.getName()){
			if(item.getQuantity() > 0){
				item.updateQuantity();
				(*m_lstItem[i]).m_serialNumber = item.getSerialNumber();
				(*m_lstItem[i]).m_fillState = true;
				std::cout << "Filled " << m_name << ", " << m_product << "[" << (*m_lstItem[i]).m_itemName << "]" << std::endl;
			}
		}
	}

}

void CustomerOrder::display(std::ostream& os) const{
/*
CUSTOMER_NAME - PRODUCT
[SERIAL] ITEM_NAME - STATUS
[SERIAL] ITEM_NAME - STATUS
...
SERIAL - a field of width 6
ITEM_NAME - a field of size m_widthField
STATUS is either FILLED or MISSING
you will have to use IO manipulators for the output.
*/
	os << std::left << m_name << " - " << m_product << std::endl;
	for (auto i = 0u; i < m_cntItem; ++i){
		os << std::setw(6) << std::setfill('0') << "[" << (*m_lstItem[i]).m_serialNumber << std::setfill(' ') << "] " 
		   << std::left << std::setw(m_widthField) << (*m_lstItem[i]).m_itemName 
		   << " - " << (getItemFillState((*m_lstItem[i]).m_itemName) ? "FILLED" : "MISSSING")<< std::endl;
	}


}

