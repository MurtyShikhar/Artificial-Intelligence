//
//  matchingCost.cpp
//  AI-1
//
//  Created by Shikhar on 03/02/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//


#include "matchingCost.h"


void MatchingCost::initialize(const vector<vector<int> > & a, const map<char,int>& b, int x){ costMatrix = a; charMap = b; CC = x;}


int MatchingCost::operator()(char a, char b) const
{
    int x = charMap.at(a), y = charMap.at(b);
    
    return costMatrix[y][x];
}


MatchingCost::MatchingCost(const MatchingCost& rhs)
{
    costMatrix = rhs.costMatrix;
    charMap = rhs.charMap;
}


MatchingCost& MatchingCost::operator=(const MatchingCost& rhs)
{
    if (this == &rhs)
        return *this;
    
    costMatrix = rhs.costMatrix;
    charMap = rhs.charMap;
    return *this;
}


