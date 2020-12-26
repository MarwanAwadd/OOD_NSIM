//
//  LOE.hpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#ifndef LOE_hpp
#define LOE_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class LOE{
public:
    void operations (int DM[], int d1, int d2, int d3, int t);
    string Line1 (int DM[], int d1, int d2, int d3, int t);
    string Line2 (int DM[], int d1, int d2, int d3, int t);
};
#endif /* LOE_hpp */
