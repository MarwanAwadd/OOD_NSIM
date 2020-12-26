//
//  LOE.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "LOE.hpp"

void LOE :: operations(int DM[], int d1, int d2, int d3, int t){
    if(DM[d1] <= DM[d2]){
        DM[d3] = 1;
        string output1 = Line1(DM, d1, d2, d3, t);
        cout << output1;
    }
    else{
        DM[d3] = 0;
        string output2 = Line2(DM, d1, d2, d3, t);
        cout << output2;
    }
}

string LOE :: Line1(int DM[], int d1, int d2, int d3, int t){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM stored 1 in mem address " << d3 << " because " << DM[d1] << " of address " << d1 << " was less than or equal to " << DM[d2] << "stored in mem address " << d2 << ".\n";
    return sss.str();
}

string LOE :: Line2(int DM[], int d1, int d2, int d3, int t){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM stored 0 in mem address " << d3 << " because " << DM[d1] << " of address " << d1 << " was greater than " << DM[d2] << "stored in mem address " << d2 << ".\n";
    return sss.str();
}
