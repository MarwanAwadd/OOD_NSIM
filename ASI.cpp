//
//  ASI.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "ASI.hpp"

void ASI :: operations(int DM[], int d1, int d2, int t){
    DM[d2] = d1;
    string output = Line(d1, d2, t);
    cout << output;
}

string ASI :: Line(int d1, int d2, int t){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM stored value " << d1 << " in memory address " << d2 << ".\n";
    return sss.str();
}
