//
// Created by shehap on 11/26/2023.
//

#include <bits/stdc++.h>
#include "Preprocessing.h"

using namespace std;

class Node{
public:
    string name;
    int freq{};
    vector<Node*>child;
};

class Tree{
public:
    Node *root;
    Tree(){
        root = new Node;
        root->name="root";
        root->freq=-1;
    }
};



Tree build_Tree(
        const vector<vector<string>>& transactions
);

map<string,vector<vector<string>>> get_cond_pattern_base(Tree tree);

void get_all_freq(const vector<freq>&c1Frequent,
                  map<string,vector<vector<string>>>conditional_pattern_base,
                  vector<vector<string>>*freq,
                  vector<string>curPath);