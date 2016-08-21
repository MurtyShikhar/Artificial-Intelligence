//
//  state.h
//  AI-1
//
//  Created by Shikhar on 31/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#ifndef __AI_1__state__
#define __AI_1__state__

#include <stdio.h>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
using namespace std;


class state{
private:
    vector<int> coords;
    vector<int> numDashes;
    
public:
    
    vector<string> solution;
    state(size_t size)                                        // constructor needed for creating the initial state
    {
        coords.resize(size, -1);
        numDashes.resize(size,0);
        solution.resize(size, "");
        
    }
    
    state()                                                  //default constructor should never be explicitlycalled
    {
        coords.resize(10, -1);
        numDashes.resize(10, 0);
        solution.resize(10, "");
        
    }
    
    void addDash(int i) {
        numDashes[i]++;}                           // utility function for adding dashes
    
   
    
    state& operator=(const state& rhs)                      // copy assignment operator
    {
        
        coords = rhs.coords;
        numDashes = rhs.numDashes;
        solution = rhs.solution;
        
        return *this;
    }
    
    bool operator<(const state& rhs) const;                 // for efficiently storing in a set

    
    state(const state& );                                   // copy constructor
    
    int& operator[](size_t);                                   // square bracket overload
    int dashesInsertedAt(size_t) const;
    bool operator==(const state& rhs) const;                // const correct equality operator
    const int& operator[](size_t i) const;                  // const correct square bracket overload
    
};
#endif /* defined(__AI_1__state__) */
