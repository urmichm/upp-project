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
    
    std::vector<T> karatsuba(const std::vector<T>& a, const std::vector<T>& b) {
        size_t n = a.size();
        if (n == 1) {
            std::vector<T> res(1);
            res[0] = a[0] * b[0];
            return res;
        }
        size_t m = n / 2;
        
        std::vector<T> a0(a.begin(), a.begin() + m);
        std::vector<T> a1(a.begin() + m, a.end());
        
        std::vector<T> b0(b.begin(), b.begin() + m);
        std::vector<T> b1(b.begin() + m, b.end());

        std::vector<T> res(2 * n - 1);
        std::vector<T> a0b0 = karatsuba(a0, b0);
        std::vector<T> a1b1 = karatsuba(a1, b1);
        
        // make sum in a01 b01
        for (size_t i = 0; i < m; i++) {
            a1[i] += a0[i];
            b1[i] += b0[i];
        }
        std::vector<T> sums = karatsuba(a1, b1);

        // error
        for (int i = 0; i < n - m; i++) {
            res[i] += a0b0[i];
            res[i + n] += a1b1[i];
        }
        for (int i = 0; i < m; i++) {
            res[i + m] += sums[i] - a0b0[i] - a1b1[i];
        }

        return res;
    }
    
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
        
        while (res.size() > 1 && res.back() == 0){
            res.pop_back();
        }
        
        return polynomial<T>( res );
    }

    
    polynomial<T> karatsuba(const polynomial<T>& other)
    {
        std::vector<T> a(coef);
        std::vector<T> b(other.coef);
        
        const size_t n = std::max(a.size(), b.size());
        
        // Pad the polynomials with zeros to make them the same size
        if (a.size() < n) a.resize(n, 0);
        if (b.size() < n) b.resize(n, 0);
        
        std::vector<T> res = karatsuba(a, b);
        
        // Remove leading zeros
        while (res.size() > 1 && res.back() == 0) res.pop_back();

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
        const size_t max_degree = std::max(size(), other.size());
        std::vector<T> c_coef(max_degree, 0);
        
        for(size_t i = 0; i < size(); i++)
        {
            c_coef[i] = coef[i];
        }
        
        for(size_t i = 0; i < other.size(); i++)
        {
            c_coef[i] = coef[i] + other[i];
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
            c_coef[i] = coef[i] - other[i];
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
