//
//  AND.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "AND.hpp"

    
void AND :: operations(int DM[], int d1, int d2, int d3, int t){
    int x = DM[d1];
    int y = DM[d2];
    DM[d3] = x + y;
    string output = Line(DM, d1, d2, d3, t, x, y);
    cout << output;
//    cout << "Thread " << t + 1 << ": " << " The SIM added memory address " << d1 << " with value " << x << " to memory address " << d2 << " with value " << y << " and stored the result " << DM[d3] << " in memory address " << d3 << ".\n";
}

string AND :: Line(int DM[], int d1, int d2, int d3, int t, int x, int y){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM added mem address " << d1 << " with value " << x << " to mem address " << d2 << " with value " << y << " and stored the result " << DM[d3] << " in memory address " << d3 << ".\n";
    return sss.str();
}
