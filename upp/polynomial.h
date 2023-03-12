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
    
    
    T operator() (T x){
        T result = 0;
        for(size_t i=0; i<coef.size(); i++){
            result += (coef[i] * pow(x, i));
        }
        return result;
    }
    
    std::string to_string(void) {
        std::string result = "";
        size_t const deg = this->deg();

        result += std::to_string(coef[deg]);
        if(deg != 0 )
            result += " x^" + std::to_string(deg);
        
        for(size_t i = 0; i <= (deg-1); i++)
        {
            const size_t c = deg - 1 - i;
            result += " + " + std::to_string(coef[c]);
            if(c == 1)
                result += " x";
            else if(c != 0 )
                result += " x^" + std::to_string(c);
        }

        return result;
    }
    
};


} // end namespace upp

#endif /* polynomial_h */
