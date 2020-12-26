//
//  NEG.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "NEG.hpp"

void NEG :: operations(int DM[], int d1, int d2, int t){
    int x = DM[d1];
    DM[d2] = -x;
    string output = Line(DM, d1, d2, t, x);
    cout << output;
//    cout << "Thread " << t + 1 << ": " << " The SIM inversed the sign in memory address " << d1 << " with value " << x << " in memory address " << d2 << " which is now " << DM[d2] << "." << endl;
}

string NEG :: Line(int DM[], int d1, int d2, int t, int x){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM inversed the sign in memory address " << d1 << " with value " << x << " in memory address " << d2 << " which is now " << DM[d2] << ".\n";
    return sss.str();
}
