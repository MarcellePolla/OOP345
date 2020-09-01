// Workshop 8 - Smart Pointers

#include <memory>
#include <vector>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for(size_t i = 0; i < desc.size(); i++){
			for(size_t j = 0; j < price.size(); j++){
					if(desc[i].code == price[j].code){
						Product *p = new Product(desc[i].desc, price[j].price);
						p->validate();
						priceList += p;
						delete p;
						p = nullptr;	
					}
				}
		}

		return priceList;
	}
}