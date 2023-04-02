//
//  main.cpp
//  upp
//
//  Created by Mikhail Urmich on 3/3/23.
//

#include <iostream>

#include "polynomial.h"

typedef  int  testtype;

void karatsuba()
{
    upp::polynomial<testtype> a(std::vector<testtype>({1, 2, 3,9 ,8, 0, 8 , 3}));
    upp::polynomial<testtype> b(std::vector<testtype>({3, 2, 5, 7, 1}));
    upp::polynomial<testtype> c = a.karatsuba(b);
    
    for(size_t i = 0; i < c.size();  i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    
    upp::polynomial<testtype> expected = a.multiply(b);
    for(size_t i = 0; i < expected.size();  i++){
        std::cout << expected[i] << " ";
    }
    std::cout << std::endl;
    
}



int main(int argc, const char * argv[])
{
    karatsuba();
    return 0;
}






