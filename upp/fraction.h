//
//  fraction.h
//  upp
//
//  Created by Mikhail Urmich on 3/3/23.
//

#ifndef fraction_h
#define fraction_h

#include <numeric>
#include <cmath>
#include <iostream>

namespace upp {

template <class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
class fraction {

private:
    
    T numerator;
    T denominator;

public:

    fraction() : numerator(0), denominator(1) { }
    
    fraction(T num) : numerator(num), denominator(1) { }
    
    fraction(T num, T den)
    {
        if(den == 0)
            throw std::invalid_argument("denominator cannot be 0.");
        
        bool sign = (num < 0) ^ (den < 0);
        
        if(num < 0) num = -num;
        if(den < 0) den = -den;
        
        const T gcd = std::gcd(num, den);
        
        this->numerator = num / gcd;
        this->denominator = den / gcd;
        
        if(sign)
            this->numerator *= (-1);
    }
    
    fraction(const fraction& other) : numerator(other.numerator), denominator(other.denominator) {}
    
    T get_numerator(void)
    {
        return this->numerator;
    }
    
    T get_cnumerator(void) const
    {
        return this->numerator;
    }

    T get_denominator(void)
    {
        return this->denominator;
    }

    T get_cdenominator(void) const
    {
        return this->denominator;
    }
    
    bool operator==(const fraction& other)
    {
        return (this->numerator == other.numerator) && (this->denominator == other.denominator);
    }
    
    bool operator!=(const fraction& other)
    {
        return !(*this == other);
    }

    bool operator>(const fraction& other)
    {
        const T common_denominator = std::lcm(this->denominator, other.denominator);
        
        const T this_numerator = this->numerator * (common_denominator / this->denominator);
        const T other_numerator = other.numerator * (common_denominator / other.denominator);

        return this_numerator > other_numerator;
    }

    bool operator<(const fraction& other)
    {
        const T common_denominator = std::lcm(this->denominator, other.denominator);
        
        const T this_numerator = this->numerator * (common_denominator / this->denominator);
        const T other_numerator = other.numerator * (common_denominator / other.denominator);

        return this_numerator < other_numerator;
    }

    bool operator<=(const fraction& other){
        return (*this < other) || (*this == other);
    }

    bool operator>=(const fraction& other){
        return (*this > other) || (*this == other);
    }

    fraction<T> operator+(const fraction<T>& other)
    {
        const T common_denominator = std::lcm(this->denominator, other.denominator);
        
        const T this_numerator = this->numerator * (common_denominator / this->denominator);
        const T other_numerator = other.numerator * (common_denominator / other.denominator);
        
        return fraction<T>(this_numerator + other_numerator, common_denominator);
    }
    
    fraction<T> operator-(const fraction<T>& other)
    {
        const T common_denominator = std::lcm(this->denominator, other.denominator);
        
        const T this_numerator = this->numerator * (common_denominator / this->denominator);
        const T other_numerator = other.numerator * (common_denominator / other.denominator);
        
        return fraction<T>(this_numerator - other_numerator, common_denominator);
    }
    
    fraction<T> operator*(const fraction<T>& other)
    {
        return fraction<T>( this->numerator * other.numerator, this->denominator * other.denominator );
    }
    
    upp::fraction<T> operator/(const upp::fraction<T>& other)
    {
        return fraction<T>( this->numerator * other.denominator, this->denominator * other.numerator );
    }
    
    void operator=(const fraction<T>& other){
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    
    void operator+=(const fraction<T>& other)
    {
        *this = *this + other;
        return;
    }
    
    void operator-=(const fraction<T>& other)
    {
        *this = *this - other;
        return;
    }

    void operator*=(const fraction<T>& other)
    {
        *this = *this * other;
        return;
    }

    void operator/=(const fraction<T>& other)
    {
        *this = *this / other;
        return;
    }
    
    std::string to_string() const
    {
        return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
    }

    std::string to_string()
    {
        return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
    }

    
    friend std::ostream& operator<<(std::ostream& os, const fraction<T>& f)
    {
        os << f.to_string() ;
        return os;
    }
    
    friend fraction<T> inverse(const fraction<T>& f)
    {
        return fraction<T>(f.denominator, f.numerator);
    }
    
    friend fraction<T> abs(const fraction<T>& f)
    {
        return fraction<T>(f.numerator < 0 ? (-1)*f.numerator : f.numerator, f.denominator);
    }
    
    friend fraction<T> pow(const fraction<T>& base, const T power)
    {
        return fraction<T>(std::pow(base.numerator, power) ,
                           std::pow(base.denominator, power) );
    }

};

} // end namespace upp

#endif /* fraction_h */
