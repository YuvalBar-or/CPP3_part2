#pragma once
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits.h>
#include <typeinfo>
using namespace std; 
namespace ariel{};

 class Fraction {

        private:
            int numerator, denominator;
        
        public:
            void reduce();
            void cheeckOverFlow(long long ,long long);
            int compareTo(const Fraction &) const;

            void setNumerator(int);
            void setDenominator(int);
            int getNumerator();
            int getDenominator (); 

            Fraction(int, int);
            Fraction(float);
            Fraction();
            Fraction operator+(const Fraction&);
            Fraction operator+(float);
            Fraction operator-(const Fraction&);
            Fraction operator-(float);
            Fraction operator*(const Fraction&);
            Fraction operator*(float);
            Fraction operator/(const Fraction&);
            Fraction operator/(float);
            bool operator==(const Fraction&) const;
            bool operator==(float );
        
            bool operator >(const Fraction&)const;
            bool operator >(float );
            bool operator<(const Fraction&)const;
            bool operator<(float );
            bool operator>=(const Fraction&)const;
            bool operator>=(float);
            bool operator<=(const Fraction&)const;
            bool operator<=(float);

   
            Fraction operator++();
            Fraction operator--();
            Fraction operator++(int);
            Fraction operator--(int);

            friend std :: ostream& operator<<(std::ostream& , const Fraction&);
            friend std :: istream& operator>>(std::istream& , Fraction& );
    
        
            friend Fraction operator+(float, const Fraction&);
            friend Fraction operator-(float , const Fraction&); 
            friend Fraction operator*(float, const Fraction&);
            friend Fraction operator/(float, const Fraction&);
            friend bool operator==(float, Fraction&);
            friend bool operator>(float, const Fraction&);
            friend bool operator>=(float, Fraction&);
            friend bool operator<(float, const Fraction&);
            friend bool operator<=(float, Fraction&);

    
    
};
