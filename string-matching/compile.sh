#!/bin/bash

clear

g++ -std=c++11 mainnonopt.cpp matchingCost2.cpp -o nonopt.o

g++ -std=c++11 main.cpp dnaMatching.cpp Action.cpp dp.cpp matchingCost.cpp node.cpp state.cpp -o opt.o

