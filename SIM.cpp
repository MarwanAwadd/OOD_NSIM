//
//  SIM.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/2/20.
//

#include "SIM.hpp"
//Constructor: Sets current instruction to empty. Sets instruction memory array values to empty. Sets data memory array values to 0.
SIM::SIM(string file){
    instrLine = "";
    max = 0;
    ifstream myfile1 (file);
    if(myfile1.is_open()){
        while ( getline(myfile1, instMem[max]) )
        {
            cout << instMem[max] << endl;
            max++;
        }
        myfile1.close();
    }
    else cout << "Unable to open file" << endl;
}

SIM::~SIM(){
}

void SIM :: printInstMem(){
    for(int i = 0; i < max; i++)
        cout << instMem[i] << endl;
}

void SIM::setInstrLine(int i){
    instrLine = instMem[i];
}

void SIM::selectInst(int DM[], int t, mutex *mu){
    for(int i = 0; i < max; i++){
        setInstrLine(i);
        string instr = instrLine.substr(0,3);
        d1 = 0;
        d2 = 0;
        d3 = 0;
        extractData();
        if(instr == "ADD"){
            mu[d1].lock();
            if(d1 != d2 )
                mu[d2].lock();
            if(d2 != d3 && d1 != d3)
                mu[d3].lock();
            a.operations(DM, d1, d2, d3, t);
            mu[d1].unlock();
            mu[d2].unlock();
            mu[d3].unlock();
        }
        else if(instr == "NEG"){
            n.operations(DM, d1, d2, t);
        }
        else if(instr == "MUL"){
            mu[d1].lock();
            if(d1 != d2 )
                mu[d2].lock();
            if(d2 != d3 && d1 != d3)
                mu[d3].lock();
            m.operations(DM, d1, d1, d3, t);
            mu[d1].unlock();
            mu[d2].unlock();
            mu[d3].unlock();
        }
        else if(instr == "JPA"){
            mu[d1].lock();
            ja.operations(d1, i, t);
            mu[d1].unlock();
        }
        else if(instr == "JP0"){
            mu[d1].lock();
            if(d1 != d2)
                mu[d2].lock();
            j0.operations(DM, d1, d2, i, t);
            mu[d1].unlock();
            mu[d2].unlock();
        }
        else if(instr == "ASI"){
            mu[d1].lock();
            if(d1 != d2)
                mu[d2].lock();
            asi.operations(DM, d1, d2, t);
            mu[d1].unlock();
            mu[d2].unlock();
        }
        else if(instr == "LOE"){
            mu[d1].lock();
            if(d1 != d2 )
                mu[d2].lock();
            if(d2 != d3 && d1 != d3)
                mu[d3].lock();
            l.operations(DM, d1, d2, d3, t);
            mu[d1].unlock();
            mu[d2].unlock();
            mu[d3].unlock();
        }
        else if(instr == "HLT"){
            stringstream ss;
            ss <<"Thread " << t + 1 << ": " <<" The SIM is stopped.\n";
            cout << ss.str();
            break;
        }
        else cerr << "instruction in text is invalid" << endl;
    }
    
}

void SIM::extractData(){
    stringstream ss;
    string tempInstr = instrLine;
    /* Storing the whole string into string stream */
    ss << tempInstr;
    /* Running loop till the end of the stream */
    string temp;
    int found;
    int i = 0;
    while (!ss.eof()) {
        
        /* extracting word by word from stream */
        ss >> temp;
        
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found){
            i++;
            if(i == 1)
                d1 = found;
            else if(i == 2)
                d2 = found;
            else
                d3 = found;
        }
        
        /* To save from space at the end of string */
        temp = "";
    }
}

