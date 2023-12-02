#pragma once
//
// Created by shehap on 11/27/2023.
//
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// get the rules to build the association rules
vector<  pair < vector<string>,vector<string>> > get_rules(vector<string>frq_itemset);

// get the freq for one or more item together
int get_frequency(vector<string>items, vector<vector<string>> transactions);

// get the support for each item
float get_support(vector<string>items, const vector<vector<string>>& transactions);

// get the confidence for each rule
float get_confidence(pair<vector<string>, vector<string>>rule, vector<vector<string>> transactions);

// get the lift for each rule
float get_lift(pair<vector<string>, vector<string>> rule, const vector<vector<string>>& transactions);