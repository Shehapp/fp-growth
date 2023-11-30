#pragma once
//
// Created by shehap on 11/27/2023.
//
#include <vector>
#include <string>
#include <map>
using namespace std;

// get the rules to build the association rules
vector<  pair < vector<string>,vector<string>> > get_rules(vector<string>frq_itemset);

// get the freq for one or more item together
int get_frequency(vector<string>items, vector<vector<string>> transactions);


float get_support(pair<string, string>rule, vector<vector<string>> transactions);


float get_confidence(pair<string, string>rule, vector<vector<string>> transactions);
