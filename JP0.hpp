//
//  JP0.hpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#ifndef JP0_hpp
#define JP0_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class JP0{
public:
    void operations (int DM[], int d1, int d2, int &i, int t);
    string LineB (int d2, int t);
    string LineNB (int d1, int d2, int t);
};
#endif /* JP0_hpp */
