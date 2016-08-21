//
//  dp.cpp
//  AI-1
//
//  Created by Shikhar on 05/02/15.
//  Copyright (c) 2015 Shikhar. All rights reserved.
//

#include <stdio.h>
#include "dp.h"
#include <iterator>
#include <algorithm>
#include <iomanip>



DP::DP(const DP& rhs)

{
    a = rhs.a;
    b = rhs.b;
    mC = rhs.mC;
    alignCost = rhs.alignCost;
    costMatrix = rhs.costMatrix;
    dashes = rhs.dashes;
    CC = rhs.CC;
    
    
}

DP::DP(const string& a, const string& b , const MatchingCost& mC,int x):a(a),b(b),mC(mC), CC(x)
{
    dashes.resize(b.size() +1, vector<int>(a.size() +1, 0) );
    costMatrix.resize(b.size()+1, vector<cell>(a.size()+1, cell() ));
    initialize();
    
    
    alignCost = performDP(0, 0).first;
}

DP& DP::operator=(const DP& rhs)
{
    dashes = rhs.dashes;
    a = rhs.a;
    b = rhs.b;
    mC = rhs.mC;
    alignCost = rhs.alignCost;
    costMatrix = rhs.costMatrix;
    CC = rhs.CC;
    
    return *this;
}


void DP::printMatrix() const
{
    for (int i = 0; i < a.size() +1; i++)
    {for (int j = 0; j < b.size() +1; j++) cout << setw(4) << costMatrix[j][i].cost << " "; cout << '\n';}
    
    
    cout << "CC " << CC << '\n';
    
}

pair<int,int> DP::performDP(int i, int j)
{
    if (i == b.size() && j == a.size() ) return make_pair(0,0);
    cell& curr = costMatrix[i][j];
    if (curr.initialized()) return make_pair(curr.cost, dashes[i][j]);
    pair<int,int> aP = performDP(i+1,j);
    pair<int,int> bP = performDP(i, j+1);
    
    pair<int,int> cP = performDP(i+1,j+1);
    int k = aP.first + CC +  mC('-', b[i]), l = bP.first + CC+  mC('-', a[j]), m = cP.first + mC(b[i], a[j]);
    
    
    int t = min(k, min(l,m));
    if (t == k)
    { return make_pair(curr.setCost(k), aP.second+1); }
    if (t == l)
    {  return make_pair(curr.setCost(l), bP.second +1);}
    else
    { return make_pair(curr.setCost(m), cP.second);}
    
    
    
    
    
}


void DP::initialize()
{
    int cost = CC;
    int dashNum = 0;
    costMatrix[b.size()][a.size()].setCost(0);
    dashes[b.size()][a.size()] = 0;
    for (int i = int(a.size()-1); i >= 0; i--)
    
    {
        dashNum++;
        cost += mC('-', a[i]);
        costMatrix[b.size()][i].setCost(cost);
        dashes[b.size()][i] = dashNum;
        cost +=CC;
    
    }
    
    
    cost = CC;
    dashNum = 0;
    for (int i = int(b.size() -1); i >= 0; i--)
    {
        dashNum++;
        dashes[i][a.size()] = dashNum;
        cost += mC('-', b[i]);
        costMatrix[i][a.size()].setCost(cost); cost += CC;
    }
    
}