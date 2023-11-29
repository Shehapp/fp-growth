//
// Created by shehap on 11/26/2023.
//

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string name;
    int freq;
    vector<Node*>child;
};

class Tree{
public:
    Node *root;
    Tree(){
        root = new Node;
        root->name="root";
    }
};

struct Pattern_base{
    vector<string>items;
    int frequent;
};

Tree build_Tree(
        const vector<vector<string>>& transactions
);
map<string,Pattern_base> get_cond_pattern_base(Tree tree);
