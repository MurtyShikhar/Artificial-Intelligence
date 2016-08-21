//
//  Action.h
//  AI-1
//
//  Created by Shikhar on 31/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#ifndef AI_1_Action_h
#define AI_1_Action_h

#include <iostream>
using namespace std;
class Action {
private:
    long long actionBit;
public:
    
    
    Action();                                                           // default constructor; never call it
    Action(long long a);                                                // takes in a long long
    int operator[](int i) const;                                              // array like functionality
    
    bool isZero(){
        return actionBit == 0;
    }
    
    void setTozero(int i)
    {
        actionBit &= ~(1 << i);
        return;
    }

    
   
    bool operator<(const Action& rhs) const;                             // for efficiently storing in a set
    
    void print() const
    {
        cout << actionBit << '\n';
    }
    
    Action& operator=(const Action& rhs)                                // copy assignment operator
    {
        actionBit = rhs.actionBit;
        return *this;
    }
  
   
};


#endif
