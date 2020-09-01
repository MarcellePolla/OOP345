#ifndef SDDS_LIST_H__
#define SDDS_LIST_H__

namespace sdds{
    template <typename T,  unsigned int N>
    class List{
        T a[N];
        unsigned int count = 0;
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

}
#endif
