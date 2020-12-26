//
//  MUL.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/5/20.
//

#include "MUL.hpp"

void MUL :: operations(int DM[], int d1, int d2, int d3, int t){
    int x = DM[d1];
    int y = DM[d2];
    DM[d3] = x * y;
    string output = Line(DM, d1, d2, d3, t, x, y);
    cout << output;
//    cout << "Thread " << t + 1 << ": " << " The SIM multiplied mem address " << d1 << " with " << x << " to mem address " << d2 << " with " << y << " and stored " << DM[d3] << "in mem address " << d3 << ".\n";
}

string MUL :: Line(int DM[], int d1, int d2, int d3, int t, int x, int y){
    ostringstream sss;
    sss << "Thread " << t + 1 << ": " << " The SIM multiplied mem address " << d1 << " with " << x << " to mem address " << d2 << " with " << y << " and stored " << DM[d3] << " in mem address " << d3 << ".\n";
    return sss.str();
}
