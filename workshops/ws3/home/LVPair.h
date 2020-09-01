#ifndef SDDS_LVPAIR_H__
#define SDDS_LVPAIR_H__

#include <iostream>
#include <string>
#include <iomanip>


namespace sdds{
    template <typename L, typename V>
    class LVPair{
        L _label;
        V _value;
        public:
        //zero argument constructor
        LVPair() : _label() , _value() {}
        //constructor - initializes variables
        LVPair( const L& aa, const V& bb) : _label(aa), _value(bb) {}
        //returns label value
        const L& key() const { return _label;}
        //returns  value
        const V& value() const { return _value;}
        //displays labels and values
        virtual void display(std::ostream& os) const{
            os << _label << " : " << _value << std::endl;
        }
    };

    //friend operator
    template <typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
        pair.display(os);
        return os;
    }

    template <typename L, typename V>
    class SummableLVPair : public LVPair<L, V>{
        static V _initialValue;
        static size_t minWidth;
        public:
        //returns initial value
        static const V& getInitialValue() { return _initialValue; }
        //default constructor
        SummableLVPair() {};
        //constructor 
        SummableLVPair(const L& lbl, const V& val): LVPair<L,V>::LVPair(lbl, val) {
            if(minWidth < lbl.size()){
                minWidth = lbl.size();
            }
        }
        //adds values with same label
        V sum(const L& lbl, const V& val) const{
            V sum = val;
            if(LVPair<L, V>::key() == lbl){
                sum = LVPair<L, V>::value() + val;
            }
            return sum;
        }
        //sets alignment and uses display from parent class
        void display(std::ostream& os) const{
            os << std::left << std::setw(minWidth);
            LVPair<L, V>::display(os);
            os << std::right;
        }
    };
//class variable initialization
    template <typename L, typename V>
    size_t SummableLVPair<L,V>::minWidth = 0;
//template specification for string types
    template<>
    std::string SummableLVPair<std::string, std::string>::_initialValue = "";
//template specification for int types
    template<>
    int SummableLVPair<std::string, int>::_initialValue = 0;
//template specification for string summation
    template<>
    std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val) const{
        std::string sum;

            if(LVPair<std::string, std::string>::key() == lbl){
                if(val != "" && LVPair<std::string, std::string>::value() != "")
                    sum = val + ", " + LVPair<std::string, std::string>::value();
                else
                    sum = LVPair<std::string, std::string>::value();
            }
            return sum;
    }

}

#endif