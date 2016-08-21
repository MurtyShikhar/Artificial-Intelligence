//
//  matchingCost.h
//  nonOpt
//
//  Created by Shikhar on 10/02/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#ifndef __nonOpt__matchingCost__
#define __nonOpt__matchingCost__


#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class MatchingCost{
private:
    vector<vector<int> > costMatrix;
    
    map<char,int> charMap;
    
    
    
    
public:
    int CC;
    
    /* CTORS, COPY CTORS, COPY ASSIGNMENT */
    void initialize(const vector<vector<int> > & a, const map<char,int>& b,int c);
    
    MatchingCost() {}
    
    MatchingCost& operator=(const MatchingCost& rhs);
    MatchingCost(const MatchingCost& rhs);
    
    
    
    /* given 2 chars a and b, gives the cost of matching them */
    
    int operator()(char a, char b) const;
    
    
};

#endif /* defined(__nonOpt__matchingCost__) */
