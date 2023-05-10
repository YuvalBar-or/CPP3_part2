#include "Fraction.hpp"
using namespace std;
using namespace ariel; 

// constructors 
Fraction::Fraction(int num1, int num2) {
    if (num2 == 0){
        throw invalid_argument ("demon cant be 0");
    }
    if (typeid(num1) != typeid(int) || typeid (num2) != typeid(int)){
        throw invalid_argument (" denom and numerator must be int type");
    }
    if ((num2 <0 && num1<0) || (num2<0 && num1>=0)){
        num1 *= -1;
        num2 *= -1;
    }
    this->denominator = num2;
    this->numerator = num1;
    this->reduce();
}

Fraction::Fraction(float num){
    if (typeid(num) != typeid(float)){
        throw invalid_argument("Error: frac must be a float");
    }
    this->numerator = num*1000;
    this->denominator = 1000;
    this->reduce();
    
}

void Fraction::setNumerator(int number1){
    this->numerator = number1;
}

void Fraction :: setDenominator(int number2){
    this->denominator = number2; 
}

int Fraction::getNumerator()
{
    return numerator;
}
int Fraction::getDenominator()
{
    return denominator;
}

Fraction :: Fraction (){
    this->numerator =0;
    this->denominator =1;  
}


// helpers 
void Fraction::reduce(){
     int gcds = std::gcd (this-> getNumerator(), this->getDenominator());
     this-> denominator = denominator / gcds ; 
     this-> numerator = numerator / gcds ; 
}

void Fraction :: cheeckOverFlow(long long number1 ,long long number2) {
    int MAX_INT = numeric_limits<int>::max();
    int MIN_INT = numeric_limits<int>::min();
    if (number1 < INT_MIN || INT_MAX < number1){
        throw overflow_error("result overflows");
    }
    if (number2 < INT_MIN || INT_MAX < number2){
       throw overflow_error("result overflows"); 
    }
}

int Fraction::compareTo(const Fraction &other) const {
    int number1 = numerator * other.denominator ; 
    int number2 = other.numerator * denominator; 

    if (number1 > number2){
        return 1; 
    }
    if (number1 == number2){
        return 0; 
    }
    return -1; 
}

// binary operators

// +
Fraction Fraction::operator+(const Fraction& frac){
    // using a/b + c/d = (a*d + c*b)/b*d
    long long NEWnum = (long long)this->numerator * frac.denominator + (long long)this->denominator * frac.numerator;
    long long NEWdenom = (long long)this->denominator * frac.denominator;
    cheeckOverFlow(NEWnum ,NEWdenom);
    return Fraction(NEWnum ,NEWdenom);
    
}

Fraction Fraction :: operator+(float num){
    Fraction frac (num*1000 ,1000);
    return frac + *this; 
}

Fraction operator+(float f, const Fraction& frac) {
    Fraction frac2 (f*1000,1000);
    return frac2 + frac;
}


//-
Fraction Fraction::operator-(const Fraction& frac){
   // using a/b - c/d = (a*d - c*b)/b*d 
    long long NEWnum = (long long)this->numerator * frac.denominator - (long long)this->denominator * frac.numerator;
    long long NEWdenom = (long long)this->denominator * frac.denominator;
    cheeckOverFlow(NEWnum ,NEWdenom);
    return Fraction(NEWnum ,NEWdenom);
}

Fraction Fraction :: operator-(float num){
    Fraction frac (num*1000 ,1000);
    return *this - frac;  
}

Fraction operator-(float f, const Fraction& frac){
    Fraction frac2 = Fraction(f);
    return frac2 - frac; 
}


// *
Fraction Fraction :: operator*(const Fraction& frac){
    // using a/b * c/d = (a*c)/(b,d)
    long long NEWnum = (long long)this->numerator * frac.numerator;
    long long NEWdenom = (long long)this->denominator * frac.denominator;
    cheeckOverFlow(NEWnum ,NEWdenom);
    return Fraction(NEWnum ,NEWdenom);
}

Fraction Fraction :: operator*(float num){
    Fraction frac (num*1000 ,1000);
    return frac * *this; 
}

Fraction operator*(float f, const Fraction& frac){
    Fraction frac2 (f*1000,1000);
    return frac2 * frac;
}


// / 
Fraction Fraction :: operator/(const Fraction& frac){
  // using (a/b)/(c/d) = a/b*d/c
    long long NEWnum = (long long)this->numerator * frac.denominator;
    long long NEWdenom = (long long)this->denominator * frac.numerator;
    if(NEWdenom ==0){
        throw std::runtime_error("Denominator cannot be 0!");
    }
    cheeckOverFlow(NEWnum ,NEWdenom);
    return Fraction(NEWnum ,NEWdenom);
}

Fraction Fraction :: operator/(float num){
    Fraction frac (num*1000 ,1000);
    return  *this / frac;
}

Fraction operator/(float f, const Fraction& frac){
    Fraction frac2 (f*1000,1000);
    return frac2 / frac;
}


// Comparison operators

// == 
bool Fraction :: operator==(const Fraction& fr)const{
    if (this->numerator == fr.numerator && this->denominator == fr.denominator){
        return true;
    }
    return false;
}

bool Fraction :: operator==(float num){
    Fraction frac (num*1000 , 1000);
    if (this->numerator == frac.numerator && this->denominator == frac.denominator){
        return true;
    } 
    return false; 
}

bool operator==(float f, Fraction& frac){
    Fraction frac2 (f*1000,1000);
    if (frac.compareTo(frac2) == 0){
        return true;
    }
    return false;
}


// >
bool Fraction :: operator>(const Fraction& frac)const {
    if (compareTo(frac)>0){
        return true;
    }
    return false;
}

bool Fraction :: operator>(const float num){
    Fraction frac (num*1000,1000);
        if (compareTo(frac)>0){
        return true;
    }
    return false;
}

bool operator>(float f, const Fraction& frac){
    Fraction frac2 (f*1000,1000);
    if (frac.compareTo(frac2)< 0){
        return true;
    }
    return false;
}


// <
bool Fraction :: operator<(const Fraction& frac)const{
    if (compareTo(frac)<0){
        return true;
    }
    return false;
}

bool Fraction :: operator<(const float num){
    Fraction frac (num*1000,1000);
    if (compareTo(frac)<0){
        return true;
    }
    return false; 
}

bool operator<(float f, const Fraction& frac){
    Fraction frac2 (f*1000,1000);
    if (frac.compareTo(frac2) > 0){
        return true;
    }
    return false;
}


// >=
bool Fraction :: operator>=(const Fraction& frac)const {
    if (compareTo(frac) >= 0){
        return true;
    }
    return false;
}

bool Fraction :: operator>=(const float num){
    Fraction frac (num*1000,1000);
    if (compareTo(frac)>= 0){
        return true;
    }
    return false; 
}

bool operator>=(float f,Fraction& frac){
    Fraction frac2 (f*1000,1000);
    if (frac.compareTo(frac2) <= 0){
        return true;
    }
    return false; 
}


// <=
bool Fraction :: operator<=(const Fraction& frac)const{
        if (compareTo(frac)<= 0){
        return true;
    }
    return false;
}

bool Fraction :: operator<=(const float num){
    Fraction frac (num*1000,1000);
    if (compareTo(frac)<= 0){
        return true;
    }
    return false;
}

bool operator<=(float f, Fraction& frac){
    Fraction frac2 (f*1000,1000);
    if (frac.compareTo(frac2) >= 0){
        return true;
    }
    return false;
}



// perfix and postfix
Fraction Fraction :: operator++(){
    //using a/b++ = a/b+b/b = a/b+1
    this->numerator += this->denominator;
    return *this;
}

Fraction Fraction :: operator--(){
    // using a/b-- = a/b-b/b = a/b-1
    this->numerator -= this->denominator;
    return *this;
}

Fraction Fraction :: operator++(int num ){
    Fraction frac = *this;
    numerator += denominator;
    return frac; 
}

Fraction Fraction :: operator--(int num){
    Fraction frac = *this;
    numerator -= denominator;
    return frac;   
}



// cin && cout
std::ostream &operator<<(std::ostream &stream, const Fraction &fraction){
    // given a fraction (a,b) returns a/b
    stream << fraction.numerator << "/" << fraction.denominator;
    return stream;
}

std::istream &operator>>(std::istream &stream, Fraction &fraction) {
     int number, denom;
    bool created = false;
    if(stream >> number && stream >> denom){
            if(denom==0){
                throw std::runtime_error("denominator can't be zero");
            }
            fraction = Fraction(number, denom);
            created = true;
    }
    
    if(!created){
        throw std::runtime_error("arguments problem");
    }
    return stream;
}








