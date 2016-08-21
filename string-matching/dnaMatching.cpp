//
//  dnaMatching.cpp
//  AI-1
//
//  Created by Shikhar on 29/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#include <stdio.h>

#include <algorithm>
#include "dp.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include "dnaMatching.h"
#include "Action.h"


using namespace std;


state dnaMatching::performAction(const Action& a, const State& s) const{
    State succ = s; // copy constructor
    for (int i = 0; i < pSize; i++)
    {
        succ[i] += a[i];
        if (a[i] == 0) {succ.addDash(i); succ.solution[i].append("-");}
        else succ.solution[i].append(1, sequences[i][succ[i]]);
    
    
    }
    return succ;
    
    
}


int dnaMatching:: h(const state& s) const
{
    int cost = 0;
    for (int i = 0; i < sequences.size(); i++)
    {
       
        for (int j = i+1; j < sequences.size(); j++)
            cost += vectorofDPs[i][j].at(s[i], s[j]);
        
    }
    
   
    int max_t = -1;
    for (int i =0; i <pSize; i++)
    {
        int t = (int)sequences[i].length() + s.dashesInsertedAt(i);
        max_t = max(max_t, t );
    }
    
    
    for (int i = 0; i < pSize; i++)
    {
        int t = (int)sequences[i].length()  + s.dashesInsertedAt(i);
        cost += CCstar*(max_t - t);
    }
  
    return cost;
}




int dnaMatching:: cost(const Action& a,const  State& s) const
{
    State nxt = performAction(a,s);
    int cost = 0;
    char t;
    for (int i = 0; i < pSize; ++i)
    {
        if (nxt[i] == s[i])
        {cost += CCstar;
        for (int j = i+1; j < pSize; j++)
           if (nxt[j] == s[j]) cost += m('-', '-');
           else cost += m('-', sequences[j][nxt[j]]);
        }
        
        else
        {
            t = sequences[i][nxt[i]];
            for (int j = i+1; j < pSize; j++)
                if (nxt[j] == s[j]) cost += m(t, '-');
                else cost += m(t,sequences[j][nxt[j]]);
        }
    }
        
        
    //cout<<cost<<'\n';

    return cost;
}

//! returns true if s is a goal state;false otherwise
bool dnaMatching::goal_test(const State& s) const
{
    for (int i = 0; i < pSize; ++i)
        if (s[i] != sequences[i].length() -1)
            return false;
    return true;
}






dnaMatching& dnaMatching::operator=(const dnaMatching& rhs)
{
    sequences = rhs.sequences;
    CCstar = rhs.CCstar;
    pSize = rhs.pSize;
    initState = rhs.initState;
    time = rhs.time;
    m = rhs.m;
    vectorofDPs = rhs.vectorofDPs;
    return *this;
}


dnaMatching::dnaMatching(const dnaMatching& rhs)
{
   // cout << "Copy constructor called" << '\n';
    sequences = rhs.sequences;
    CCstar = rhs.CCstar;
    pSize = rhs.pSize;
    initState = rhs.initState;
    time = rhs.time;
    m = rhs.m;
    vectorofDPs = rhs.vectorofDPs;
    
    //equalize(rhs);
    
}


