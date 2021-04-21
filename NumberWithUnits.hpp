//
// AUTHOR: Tal Zichlinsky
// Header file for class NumberWithUnits

namespace ariel{

    class NumberWithUnits{

        public:
            NumberWithUnits(int num, string unit);

            static void read_units(std::ifstream &u_fle);

            //-----------------------------
            // Arithmetic Operators
            //-----------------------------

            NumberWithUnits operator-();
            NumberWithUnits operator-(NumberWithUnits num);
            NumberWithUnits operator-=(NumberWithUnits num);

            NumberWithUnits operator+();
            NumberWithUnits operator+(NumberWithUnits num);
            NumberWithUnits operator+=(NumberWithUnits num);

            //-----------------------------
            // Comparison Operators
            //-----------------------------

            bool operator!=(NumberWithUnits num);
            bool operator==(NumberWithUnits num);

            bool operator<=(NumberWithUnits num);
            bool operator>=(NumberWithUnits num);

            bool operator<(NumberWithUnits num);
            bool operator>(NumberWithUnits num);

            //-----------------------------
            // Increment Decrement Operators
            //-----------------------------

            NumberWithUnits operator--();
            NumberWithUnits operator--(int dummy);

            NumberWithUnits operator++();
            NumberWithUnits operator++(int dummy);

            //-----------------------------
            // Friend Operators
            //-----------------------------

            friend NumberWithUnits operator*(double d, NumberWithUnits num);
            
                //-----------------------------
                // I/O Operators
                //-----------------------------
            friend ostream& operator<<(ostream& out, NumberWithUnits num);
            friend istream& operator>>(istream& out, NumberWithUnits num);
    };

}