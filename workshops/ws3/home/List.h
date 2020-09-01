#ifndef SDDS_LIST_H__
#define SDDS_LIST_H__
#include "LVPair.h"

namespace sdds{
    template <typename T,  unsigned int N>
    class List{
        T a[N];
        size_t count = {0u};
        public:
        //returns the amount of items in the array
        size_t size() const{ return count; }
        //returns the item in the requested position
        const T& operator[](size_t i){ return a[i]; }
        //adds items to the array
        void operator+=(const T& tt){
            if(count < N){
                a[count] = tt;
                count++;
            }
        }
    };

//derived class template
    template< typename L, typename V, typename T, unsigned int N>
    class LVList : public List<T, N>{
        public:
//accumulates summable pairs
        V accumulate(const L& label) const{
            SummableLVPair<L, V> sumInstance;
            V accumulator = sumInstance.getInitialValue();
            for(size_t i = 0; i < ((List<T, N>&) *this).size(); i++){
                if(label == ((List<T, N>&) *this)[i].key())
                    accumulator = ((List<T, N>&) *this)[i].sum(label, accumulator);
            }
            return accumulator;
        }
    };

}
#endif
