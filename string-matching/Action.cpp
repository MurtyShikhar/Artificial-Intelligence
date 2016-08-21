//
//  Action.cpp
//  AI-1
//
//  Created by Shikhar on 31/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#include <stdio.h>
#include "Action.h"

Action::Action():actionBit(0){}

Action::Action(long long a): actionBit(a){}


// for efficiently storing in a set
bool Action::operator<(const Action& rhs) const
{
    return actionBit < rhs.actionBit;
}


int Action::operator[](int i) const
{
    
    return (actionBit & (1 << i) ) == 0 ? 0 : 1;
}




