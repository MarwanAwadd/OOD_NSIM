//
//  JP0.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "JP0.hpp"

void JP0 :: operations(int DM[], int d1, int d2, int &i, int t){
    if(DM[d1] == 0){
        i = d2 - 1;
        string outputB = LineB(d2, t);
        cout << outputB;
    }
    else {
        string outputNB = LineNB(d1, d2, t);
        cout << outputNB;
    }
}

string JP0 :: LineB(int d2, int t){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM jumped to inst address " << d2 << " because in1 was equal to zero.\n";
    return sss.str();
}

string JP0 :: LineNB(int d1, int d2, int t){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM did not jump to inst address " << d2 << " because mem address at " << d1 << " was not equal to zero.\n";
    return sss.str();
}
