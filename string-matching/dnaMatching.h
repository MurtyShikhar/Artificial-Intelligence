//
//  dnaMatching.h
//  AI-1
//
//  Created by Shikhar on 29/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#ifndef AI_1_dnaMatching_h
#define AI_1_dnaMatching_h
#include "state.h"
#include "Action.h"
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "dp.h"
#include "matchingCost.h"
using namespace std;

class dnaMatching{
    
private:
    
    
    
    int maxString;
    double time;
    size_t pSize;                             // size is the number of strings taken as input
    
    
    /* variables for handling the costs */
    
    int CCstar;                                    // cost of adding a dash

   // vector<vector<int> > costMatrix;                // the costMatrix as specified by the input
    
    

    
    
    vector<vector<DP> > vectorofDPs;

    
    /*change charInverse */

public:
    
    typedef state State;
    state initState;
    
    vector<string> sequences;
    
    

    
    MatchingCost m;

    
    dnaMatching(){}
    
    dnaMatching& operator=(const dnaMatching&);
    dnaMatching(const dnaMatching&);
    
    friend void initialize(dnaMatching&, ifstream&);
    
    State performAction(const Action& a,const State& s) const;       // performs action on a given state and returns the result
    int h(const State& s) const;                             // heuristic function of the state. modify only this
    int cost(const Action& a,const State& s) const;                      // cost of performing an action on a state. TODO
    bool goal_test(const State& s) const;                      // boolean to check for goal state
    
    
    
   int probSize() const {return (int)pSize;}

};


#endif
