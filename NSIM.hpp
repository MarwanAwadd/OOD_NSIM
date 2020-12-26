//
//  NSIM.hpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/2/20.
//

#ifndef NSIM_hpp
#define NSIM_hpp

#include <stdio.h>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "SIM.hpp"
#include <dirent.h>
#include <mutex>
using namespace std;

class NSIM{
public:
    NSIM(string);
    ~NSIM();
    
    void selectFile();
    void setFiles();
    void Operations();
private:
    vector<SIM> NS;
    vector<thread> NST;
    vector<string> files;
    vector<string> f;
    int DM[1024];
    mutex* mu;
    string folderPath;
};
#endif /* NSIM_hpp */
