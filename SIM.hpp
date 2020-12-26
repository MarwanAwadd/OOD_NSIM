//
//  SIM.hpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/2/20.
//

#ifndef SIM_hpp
#define SIM_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <mutex>
#include "AND.hpp"
#include "NEG.hpp"
#include "MUL.hpp"
#include "JPA.hpp"
#include "JP0.hpp"
#include "ASI.hpp"
#include "LOE.hpp"


using namespace std;

class SIM//: public NSIM
{
public:
    SIM(string);
    ~SIM();
    void printInstMem();
    
    void setInstrLine(int);
    
    void selectInst(int[], int, mutex*);
    void extractData();
    
private:
    string instrLine;
    string instMem[1024];
    int d1, d2, d3;
    int max;
    
    AND a;          //should be ADD but it was created as AND by mistake
    NEG n;
    MUL m;
    JPA ja;
    JP0 j0;
    ASI asi;
    LOE l;
};
#endif /* SIM_hpp */
