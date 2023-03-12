//
//  polynomial.h
//  upp
//
//  Created by Mikhail Urmich on 3/5/23.
//

#ifndef polynomial_h
#define polynomial_h

#include <vector>
#include <cmath>

namespace upp {

template <class T>
class polynomial {

private:

    /// Vector representation of a polynomial
    /// i-th element in the vector coef is the a-th coefficient of the polynomial
    std::vector<T> coef;
    
public:
    
    polynomial(std::vector<T> coefficients) : coef(coefficients) { }
    
    polynomial(const polynomial<T>& other){
        this->coef = std::vector<T>(other.coef);
    }
    
    size_t deg(void) const {
        return coef.size() - 1;
    }
    
    size_t deg(void) {
        return coef.size() - 1;
    }
    
    T leading_coefficient() const {
        return coef[ deg() ];
    }

    T leading_coefficient() {
        return coef[ deg() ];
    }
    
    void scalar_multiply(const T a)
    {
        for(T& c : coef)
        {
            c = c * a;
        }
        return;
    }

    polynomial<T> operator+(const polynomial<T>& other)
    {
        const size_t min_degree = std::min(this->deg(), other.deg());
        std::vector<T> c_coef;
        if(this->deg() > other.deg()){
            c_coef = std::vector<T>(this->coef);
        }
        else {
            c_coef = std::vector<T>(other.coef);
        }
        
        for(size_t i=0; i <= min_degree; i++){
            c_coef[i] = this->coef[i] + other.coef[i];
        }
        
        return polynomial<T>(c_coef);
    }
    
    T operator() (T x){
        T result = 0;
        for(size_t i=0; i<coef.size(); i++){
            result += (coef[i] * pow(x, i));
        }
        return result;
    }
    
    T operator[](const size_t i) const{
        return coef[i];
    }
};


} // end namespace upp

#endif /* polynomial_h */
