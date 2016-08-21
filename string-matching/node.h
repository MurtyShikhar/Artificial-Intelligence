//
//  node.h
//  AI-1
//
//  Created by Shikhar on 29/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#ifndef AI_1_node_h
#define AI_1_node_h

#include "Action.h"
#include "state.h"
#include "dnaMatching.h"
#include <set>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iterator>
#include <stack>

using namespace std;


typedef dnaMatching Problem;


class Node{
    

    
public:
    
    
    typedef Action action;

    // default constructor should never be called
    Node(): path_cost(-1){}
    
    Node(const Problem& prob):p(prob){
      //  cout << "constructor" << '\n';
        curr = prob.initState;
        path_cost = 0;
        
    }
  
    Node(const Problem& p, int path_cost, const state& curr): p(p), path_cost(path_cost),curr(curr)
    {
        
    }
    
   
    
    Node(const Node& rhs){
        
        p = rhs.p;
        
        path_cost = rhs.path_cost;
        curr = rhs.curr;
       
    }
    
    
   
    Node& operator=(const Node& rhs)
    {
        p = rhs.p;
        path_cost = rhs.path_cost;
        curr = rhs.curr;
        return *this;
    }
    
    
//    const Node* const par() const{
//        return parent;
//    }
    
    vector<Node> expand(long long max) const;
    const state& nodeState() const;
    bool operator==(const Node& rhs) const;
    int cost() const;
    
   
    
    Node child_node(const action& ac) const
    {
        
        state next = p.performAction(ac,curr);
        int costC = path_cost + p.cost(ac,curr);
        Node child(p,costC, next);
        
        
        return child;
    }
    
    const int& pathCost() const {return path_cost;}
    
    Problem p;
    void printSolution(ofstream& o)
    {
     
        
        copy(curr.solution.begin(), curr.solution.end(), ostream_iterator<string>(o, "\n"));
        
    }
    
    
    
    
private:
    
    int path_cost;
    state curr;
    


    
    
    
};


#endif
