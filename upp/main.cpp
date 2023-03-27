//
//  main.cpp
//  upp
//
//  Created by Mikhail Urmich on 3/3/23.
//

#include <iostream>

#include "polynomial.h"
#include "fraction.h"

typedef upp::fraction<int>  int_fraction;

std::string print(const upp::polynomial<int_fraction>& pol)
{
    std::string result = "[";
    size_t const deg = pol.deg();

    for(size_t i = 0; i <= (deg); i++)
    {
        result +=  pol[i].to_string();
        if(i != deg)
            result += "  ";
    }
    result += "]";
//    std::cout <<  result << std::endl;
    return result;
}

void test_power_fraction()
{
    int_fraction fraction(3,4);
    std::cout << fraction << std::endl;
    std::cout << pow(fraction, 2) << std::endl;
    
}

void test_sum_polynomial()
{
    upp::polynomial<int_fraction> a(std::vector<int_fraction>({
        int_fraction(3,2),2,4,9,1}));
    upp::polynomial<int_fraction> b(std::vector<int_fraction>({3,2,4,7}));

    
    upp::polynomial<int_fraction> c = a + b;
    std::cout << print(c) << std::endl;
}

void test_subtract()
{
//    upp::polynomial<int_fraction> a(std::vector<int_fraction>({
//        int_fraction(3,2),2,4,9,1}));
//    upp::polynomial<int_fraction> b(std::vector<int_fraction>({3,2,4,7}));
//
//    upp::polynomial<int_fraction> c = a - b;
//    std::cout << print(a) << std::endl;
//    std::cout << print(b) << std::endl;
//    std::cout << print(c) << std::endl;
    upp::polynomial<int> a(std::vector<int>({2,5,1,2,4}));
    upp::polynomial<int> b(std::vector<int>({2,5,1}));
    upp::polynomial<int> c = a - b;
    
    for(size_t i = 0; i < c.size();  i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

void karatsuba()
{
    upp::polynomial<int> a(std::vector<int>({1, 2, 3}));
    upp::polynomial<int> b(std::vector<int>({3,2}));
    upp::polynomial<int> c = a.multiply(b);
    
    for(size_t i = 0; i < c.size();  i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

}

int main(int argc, const char * argv[])
{
//    test_sum_polynomial();
//    test_subtract();
    karatsuba();
    
//    upp::polynomial<int> p(std::vector<int>({3,2,4}));
//    const std::string str = p.to_string();
//    std::cout << str << std::endl;
//    std::cout << "f(2) = " << p(5) << std::endl;
//    std::cout << "f(1) = " << p(1) << std::endl;
//    std::cout << "f(0) = " << p(0) << std::endl;
    return 0;
}






