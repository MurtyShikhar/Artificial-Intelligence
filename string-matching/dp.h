//
//  dp.h
//  AI-1
//
//  Created by Shikhar on 29/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#ifndef AI_1_dp_h
#define AI_1_dp_h

#include <vector>
#include <string>
#include "matchingCost.h"
#include <cassert>
using namespace std;


class DP{
    
public:
    
    DP() {}  // default constructor,never call explicitly
    
    DP(const DP& rhs);
    DP& operator=(const DP& rhs);
    DP(const string& a,const string& b , const MatchingCost& mC,int x);
    
    const int& at(int i,int j) const
    {
     //   assert (i +1 >= 0 && i +1 <= b.size() && j +1 >= 0 && j +1 <= a.size() );
        return costMatrix[j+1][i+1].cost;
    }
    
     void printMatrix() const;
    
    int dashesAt(int i,int j) const
    {
        return dashes[j+1][i+1];
    }
   

    
private:
    
    
   string a;
   string b;
    vector<vector<int> > dashes;
    
    struct cell{
        
        bool initialized(){return cost != -1;}
        int cost;
        cell(): cost(-1){}
        
        cell(int cost): cost(cost){}
        int setCost(int a){ cost = a; return cost;}
    };


    
    vector<vector<cell> > costMatrix;
    
    int alignCost;
    MatchingCost mC;
    int CC;
    
    
    int costToGoal(int i,int j) {
        return performDP(j+1,i+1).first;
    }
    
    
    
    void initialize();
    pair<int,int> performDP(int i, int j);
  
    
   
    
    
};



#endif
