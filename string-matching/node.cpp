//
//  node.cpp
//  AI-1
//
//  Created by Shikhar on 01/02/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#include "node.h"
#include <functional>


const state& Node::nodeState() const
{
    return curr;
}

vector<Node> Node::expand(long long max) const
{
    
    vector<Node> successors;
    long long t = 1 << p.probSize();
    successors.reserve(t);
    
    for (long long i = 1; i < t; i++)
    {
        Action m(i);
        bool add = true;
        for (int j = 0; j < p.probSize(); j++)
        {
            int l = (int)p.sequences[j].length();
            if (curr[j] + m[j] >= l)
            {add = false; break;}
        }
        
        if (add)
        {   Node c = child_node(m);
            if (c.cost() < max)
                
                successors.push_back(c);
          //  cout << successors.size() << '\n';
        }
        
        
    }
    

    
    
    //transform(a.begin(), a.end(), successors.begin(), bind(&Node::child_node, this, std::placeholders::_1));
    return successors;
    
}





bool Node::operator==(const Node& rhs) const
{
    return curr == rhs.curr  && path_cost == rhs.path_cost;
}
// the h function needs to be implemented
int Node::cost() const
{
    return path_cost + p.h(curr);
}








