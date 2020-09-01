#ifndef COLLECTION_H
#define COLLECTION_H
#include <stdexcept>
namespace sdds{
	template<typename T>
	class Collection{
		std::string m_name;
		T* m_collection = nullptr;
		size_t m_size = 0;
		//observes an event: when an item has been added to the collection 
		//the class Collection<T> will call this function informing the client about the adition.
		void (*observer)(const Collection<T>&, const T&) = nullptr;
	public:
		//constructor
		Collection(std::string name): m_name(name), m_collection(nullptr), m_size(0){}
		const std::string& name() const{ return m_name;}
		size_t size() const{return m_size;}
		void setObserver(void (*obs)(const Collection<T>&, const T&)){
			this->observer = obs;
		}
		Collection<T>& operator+=(const T& item){
		
			bool found = false;
			for(size_t i = 0; i < size(); i++){
				if(m_collection[i].title() == item.title()){
					found = true;
				}
			}

			if(!found){
				T* hold = new T[size()];
				for(size_t i = 0; i < size(); i++){
					hold[i] = m_collection[i]; 
				}
				delete [] m_collection;
				m_collection = new T[++m_size];

				for(size_t i = 0; i < size() - 1; i++){
					m_collection[i] = hold[i]; 
				}
				m_collection[m_size - 1] = item;
				delete [] hold;

				if(observer != nullptr){
					observer(*this, m_collection[m_size - 1]);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const{
			if (idx >= m_size)
				throw std::out_of_range ("Bad index ["+ std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");
			return m_collection[idx];
		}

		T* operator[](std::string title) const{
			T* find = nullptr;
			for(size_t i = 0; i < size(); i++){
				if(m_collection[i].title() == title)
					find = &m_collection[i];
			}
			return find;
		}

		void display(std::ostream os){
			for(size_t i = 0; i < size(); i++){
				std::cout << m_collection[i];
			}
		}

		friend std::ostream& operator<<(std::ostream& os, Collection<T>& collection){
			//this->display(os);
			 for(size_t i = 0; i < collection.size(); i++){
			 		os << collection[i];
			 	}
		return os;
		}

		//destructor
		~Collection(){ 
			delete [] m_collection;
			m_collection = nullptr;
		}
		//copy operations deletion
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		Collection& operator=(Collection&&) = delete;
	};


}
#endif