//
//  NSIM.cpp
//  NSIM_Final
//
//  Created by Marwan Awad on 12/2/20.
//

#include "NSIM.hpp"
NSIM :: NSIM(string fp){
    for(int i = 0; i < 1024; i++)
        DM[i] = 0;
    folderPath = fp;
    
    mu = new mutex[1024];
}

NSIM :: ~NSIM(){
    for(int i = 0; i < 1024; i++)
    DM[i] = 0;
}

void NSIM :: selectFile(){
    DIR* dirp = opendir(folderPath.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        files.push_back(dp->d_name);
    }
    closedir(dirp);
    files.erase(files.begin(), files.begin() + 2);
    
    for(int i = 0; i < files.size(); i++){
        cout << files[i] << endl;
    }
    
}

void NSIM :: setFiles(){
    for(int i = 0; i < files.size(); i++){
        NS.push_back(files[i]);
//        NS[i].extractData();
    }
}

void NSIM :: Operations(){
    setFiles();
    
    for(int i = 0; i < NS.size(); i++){
        NST.push_back(thread(&SIM::selectInst, &NS[i], DM ,i, mu));
    }
    for(auto &th : NST)
        th.join();
}
