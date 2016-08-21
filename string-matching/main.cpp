//
//  main.cpp
//  AI-1
//
//  Created by Shikhar on 29/01/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#include <iomanip>
#include <iostream>
#include "dnaMatching.h"
#include "node.h"
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include "state.h"
#include <fstream>
#include "dp.h"
#include "Action.h"
#include <stdexcept>
#include <sstream>
#include <iterator>
#include <ctime>

using namespace std;

typedef Node node;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct compareNodes{
    bool operator()(const node& a,const node& b)
    {
        return a.cost() < b.cost() ;
    }
};









void initialize(dnaMatching& d, ifstream& f)
{
    int vocab;
    double time;
    
    f >> time;
    
    d.time = time;
    f >> vocab;
 
    
    string s;
    f.ignore();
    getline(f,s);

    
    stringstream inp(s);
    map<char,int> charMap;
    int i = 0;
    char letter;
    while (inp >> letter)
    {
        
        charMap[letter] = i;
        i++;
        if (inp.peek() == ' ' || inp.peek() == ',')
            inp.ignore();
        
        
    }
    
    charMap['-'] = i;
    
    
    string l;
    
    
    
    int k;
    f >> k;
    d.pSize = (size_t) k;
    
    vector<string> sequences;
  
    
    sequences.reserve(k);
   
    
    
    for (int i = 0; i < d.pSize; i++)
    {
        f >> s;
   
        sequences.push_back(s);
    }
    
    d.sequences = sequences;
   
    f >> d.CCstar;
    
    int maxSize = -1;
    for (int i =0; i < sequences.size(); i++)
    {   int t = (int)sequences[i].length();
        maxSize = max(t,maxSize );}
    
    int m = 0;
    for (int i = 0; i < sequences.size(); i++)
    {
        int p = (int)sequences[i].length();
        m += d.CCstar*(maxSize - p);
    }
    d.maxString = m;
    
   
    
    int tempInt;
    vector<int> temp;
    vector<vector<int> > costMatrix;
    for (int i = 0; i < vocab +1; i++)
    {
        
        temp.clear();
        for (int j = 0; j < vocab; j++)
        {
            f >> tempInt;
            
            temp.push_back(tempInt);
        }
        f >> tempInt;
        
        temp.push_back(tempInt);
        costMatrix.push_back(temp);
  
    }
    char t;
    f >> t;
  
    d.m.initialize(costMatrix, charMap, d.CCstar);
    
    


    
    vector<vector<DP> > dpVector(k, vector<DP>(k));
    clock_t t1 = clock();
    for (int i = 0; i < d.pSize; i++)
        for (int j = i+1; j < d.pSize; j++)
        {
            DP tempDp(d.sequences[i], d.sequences[j], d.m, 0);
            dpVector[i][j] =tempDp;
        }
    
    double Tme = (clock() - t1 )/ (double) CLOCKS_PER_SEC;
    
    //printf("%s:%f\n", "time taken :", Tme);
   
    d.vectorofDPs = dpVector;
   
    
   
    
    state a(d.pSize);
    d.initState = a;
    
}



class DFSBB{
    
private:
    
    node result;
    bool found;
    dnaMatching p;
    
    long long max;
    long long nodesExpanded;

public:
    
    
    void dfStack(node& root)
    {
        stack<node> s;
        s.push(root);
        node a;
        while (!s.empty())
        {
            a = s.top(); s.pop();
            if (p.goal_test(a.nodeState())) {max = a.cost(); found = true; result = a;}
            vector<node> succ = a.expand(max);
            sort(succ.begin(), succ.end(), compareNodes());
            typedef vector<node>::iterator itr;
            itr en = succ.end();
            for (itr it = succ.begin(); it != en; it++)
                s.push(*it);
            
        }
    }
    
    DFSBB(const dnaMatching& prob, bool debug = false):p(prob)
    {
        
        max = (1<<16) -1;
        nodesExpanded = 0;
        node root(p);
        //cout << "H value of root: " << root.cost() << '\n';
        clock_t t1 = clock();
        dfRecur(root, debug);
        double time = (clock() - t1 )/ (double) CLOCKS_PER_SEC;
        
        //printf("%s:%f\n", "time taken :", time);
        
//        clock_t t1 = clock();
//        dfStack(root);
//        double time = (clock() - t1 )/ (double) CLOCKS_PER_SEC;
//        
//        printf("%s:%f\n", "time taken :", time);
    }
    
    
    void dfRecur(const node& c, bool debug)
    {
        
        if (p.goal_test(c.nodeState())) {
            max = c.cost(); found = true; result = c;
            return;
        
        }
        nodesExpanded++;
        if (debug)
        {
            
            cout << "Heuristic cost " << c.cost() - c.pathCost() <<  '\n';
            cout << "Path cost " << c.pathCost() << '\n';
        }
        
        
        vector<node> succ = c.expand(max);
      
        sort(succ.begin(), succ.end(), compareNodes());
        
        typedef vector<node>::iterator itr;
        
        itr en = succ.end();
        for (itr it = succ.begin(); it != en; it++)
        {
            dfRecur(*it, debug);
        }
        
        //cout << "Done" << '\n';
        return;
    }
    
    node solution(){
        if (!found) throw std::invalid_argument( "no possible solution to this problem" );
        //cout << "Nodes expanded " << nodesExpanded << '\n';
        return result;
    }
};






int main(int argc, const char * argv[]) {
 
    dnaMatching prob;
    ifstream i;
    i.open(argv[1]);
    initialize(prob, i);
    
    
    ofstream o;
    o.open(argv[2]);

    DFSBB d(prob,false);
    //cout << "done" <<'\n';

    
    node result = d.solution();
    //cout << prob.h(result.nodeState()) << "GOAL" << '\n';
    //cout << result.cost() << '\n';
    
    
    
    result.printSolution(o);
    

}
