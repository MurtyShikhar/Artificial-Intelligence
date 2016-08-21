//
//  state.cpp
//  AI-1
//
//  Created by Shikhar on 31/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#include "state.h"


bool state::operator<(const state& rhs) const
{
    for (size_t i = 0;  i < coords.size(); i++)
        if (coords[i] < rhs[i]) return true;
            else if (coords[i] == rhs[i] && dashesInsertedAt(i) < rhs.dashesInsertedAt(i))
                return true;
    
    
    return false;
}


bool state::operator==(const state& rhs) const
{
    return coords == rhs.coords && numDashes == rhs.numDashes;
}

state::state(const state& rhs)
{
    coords = rhs.coords;
    numDashes = rhs.numDashes;
    solution = rhs.solution;
}

int& state::operator[](size_t i)
{
    assert ( i < coords.size());
    return coords[i];
}


const int& state::operator[](size_t i) const
{
    assert(i < coords.size());
    return coords[i];
}


int state::dashesInsertedAt(size_t i) const

{
    return numDashes[i];
}