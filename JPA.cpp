//
//  JPA.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "JPA.hpp"

void JPA:: operations(int d1, int &i, int t){
    i = d1 - 1;
    string output = Line(d1, i, t);
    cout << output;
//    cout << "Thread " << t + 1 << ": " << " The SIM jumped to memory address " << d1 - 1 << ".\n";
}

string JPA :: Line(int d1, int &i, int t){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM jumped to memory address " << d1 - 1 << ".\n";
    return sss.str();
}
