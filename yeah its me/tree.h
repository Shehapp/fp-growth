//
// Created by shehap on 11/26/2023.
//

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string name;
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

Tree build_Tree(
        const vector<vector<string>>& transactions
);