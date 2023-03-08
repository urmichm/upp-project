//
//  polynomial.h
//  upp
//
//  Created by Mikhail Urmich on 3/5/23.
//

#ifndef polynomial_h
#define polynomial_h

#include <vector>

namespace upp {

class polynomial {
private:
    std::vector<int> A;
    
public:
    polynomial(std::vector<int> coef){
        A = std::vector<int>(coef);
    }
};

} // end namespace upp

#endif /* polynomial_h */
