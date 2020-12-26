//
//  ASI.hpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#ifndef ASI_hpp
#define ASI_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ASI{
public:
    void operations (int DM[], int d1, int d2, int t);
    string Line (int d1, int d2, int t);
};
#endif /* ASI_hpp */
