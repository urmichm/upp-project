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

#define KARATSUBA_THRESHOLD 4

namespace upp {

template <class T>
class polynomial {

private:

    /// Vector representation of a polynomial
    /// For n coeffiecients  the polinomial is:
    /// coef[0] * X^(n-1) + coef[1] * X ^ (n-2) + .. + coef[n-1] * X^0
    /// For example polynomial 3X^2 -4X +9 is represented as  [3, -4, 9]
    std::vector<T> coef;
    

    std::vector<T> multiply(const std::vector<T>& A, const std::vector<T>& B) {
        size_t n = A.size(), m = B.size();
        std::vector<T> C(n + m - 1, 0);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                C[i+j] += A[i] * B[j];
            }
        }
        return C;
    }
    
public:
    
    polynomial(std::vector<T> coefficients) : coef(coefficients) { }
    
    polynomial(const polynomial<T>& other){
        this->coef = std::vector<T>(other.coef);
    }
    
    /// classical polynomial multiplication
    polynomial<T> multiply(const polynomial<T>& other)
    {
        std::vector<T> res = multiply(coef, other.coef);
        return polynomial<T>( res );
    }

    size_t deg(void) const {
        return coef.size() - 1;
    }
    
    size_t deg(void) {
        return coef.size() - 1;
    }

    size_t size(void) const {
        return coef.size();
    }
    
    size_t size(void) {
        return coef.size();
    }

    T leading_coefficient() const {
        return coef[0];
    }

    T leading_coefficient() {
        return coef[0];
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
        const size_t max_degree = std::max(size(), other.size());
        std::vector<T> c_coef(max_degree, 0);
        
        for(size_t i = 0; i < size(); i++)
        {
            c_coef[i] = coef[i];
        }
        
        for(size_t i = 0; i < other.size(); i++)
        {
            c_coef[i] += other[i];
        }

        return polynomial<T>(c_coef);
    }

    polynomial<T> operator-(const polynomial<T>& other)
    {
        const size_t max_degree = std::max(size(), other.size());
        std::vector<T> c_coef(max_degree, 0);
        
        for(size_t i = 0; i < size(); i++)
        {
            c_coef[i] = coef[i];
        }
        
        for(size_t i = 0; i < other.size(); i++)
        {
            c_coef[i] -= other[i];
        }

        return polynomial<T>(c_coef);
    }
    
    T operator() (T x){
        T result = 0;
        for(size_t i=0; i<coef.size(); i++){
            result += (coef[i] * pow(x, coef.size() - i - 1));
        }
        return result;
    }
    
    T operator[](const size_t i) const{
        return coef[i];
    }
};


} // end namespace upp

#endif /* polynomial_h */
