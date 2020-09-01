#ifndef SDDS_LVPAIR_H__
#define SDDS_LVPAIR_H__

#include <iostream>
#include <cstring>


namespace sdds{
    template <typename L, typename V>
    class LVPair{
        L _label;
        V _value;
        public:
        //zero argument constructor
        LVPair() : _label() , _value(0) {}
        //constructor - initializes variables
        LVPair( const L& aa, const V& bb) : _label(aa), _value(bb) {}
        //returns label value
        const L& key() const { return _label;}
        //returns  value
        const V& value() const { return _value;}
        //displays labels and values
        void display(std::ostream& os) const{
            os << _label << " : " << _value << std::endl;
        }
    };

    //friend operator
    template <typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
        pair.display(os);
        return os;
    }
}

#endif