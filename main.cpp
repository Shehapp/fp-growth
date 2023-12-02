// Fp-growth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "yeah its me/extraction.h"
#include "yeah its me/tree.h"
#include <iostream>

using namespace std;

void printTree(const Node* root, int depth = 0) {
    // Print indentation based on depth
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    // Print node information
    std::cout << root->name << " (" << root->freq << ")\n";

    // Recursively print children
    for (const auto& child : root->child) {
        printTree(child, depth + 1);
    }
}

int main()
{


    vector<vector<string>> transactions = read_input("J:\\college\\fp-growth-implementation\\data\\Horizontal_Format.csv"); //@tarek

    freopen("J:\\college\\fp-growth-implementation\\data\\result.txt","w",stdout);

    cout << "Transactions : " << endl;
    for (int i = 0; i < transactions.size(); i++) {

        for (int j = 0; j < transactions[i].size(); j++) {

            cout << transactions[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Enter min support and confident : " << endl;
    int min_support;
    float confident;
    cin >> min_support >> confident;
    set_support(min_support);



    // get frequent items l1
    vector<freq> c1Frequent = get_c1_frequent(transactions,min_support); //@anas
    //transactions w ordered item set
    transactions = rebuild_transactions(transactions, c1Frequent,min_support); //abdo
    

    cout << "c1 frequent " << endl;

    for (int i = 0; i < c1Frequent.size(); i++) {

        cout << c1Frequent[i].item << " " << c1Frequent[i].frequent << endl;

    }


    cout << "Rebuilt Transactions:" << endl;
    for (int i = 0; i < transactions.size(); i++)
    {
        for (int j = 0; j < transactions[i].size(); j++)
        {
            cout << transactions[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    //build the tree
    Tree tree = build_Tree(transactions); //@tarek

    cout << "FP-Tree" << endl;

    printTree(tree.root);

    cout << endl;


    // get conditional pattern base
    map<string, vector<vector<string>>>conditional_pattern_base = get_cond_pattern_base(tree); //@shehapoo



    // get all c1Frequent :)
    vector<vector<string>>frequents;
    vector<string>curPath;
    get_all_freq(c1Frequent, conditional_pattern_base, &frequents, curPath,min_support); //@shehapoo


    //get freq for all frequent items 
    cout << "Frequent item sets : " << endl;

    for (int i = 0; i < frequents.size(); i++)
    {
        for (int j = 0; j < frequents[i].size(); j++)
        {
            cout << frequents[i][j] << " ";
        }
        cout << " (frequency : " << get_frequency(frequents[i], transactions) << " ) " << endl;;
        
    }
    cout << endl;



    //get the confidence of each rule 
    cout << "RULES confidence :" << endl;
    for (int i = 0; i < frequents.size(); i++) {

        vector<  pair < vector<string>, vector<string>> >rules;

        rules = get_rules(frequents[i]);
        float freq_support = get_support(frequents[i],transactions);

        //for each rule get the confidence 
        for (int j = 0; j < rules.size(); j++) {

            
            for (int k = 0; k < rules[j].first.size();k++) {

                cout << rules[j].first[k]<<" ";
            }
            cout << " --> ";
            for (int k = 0; k < rules[j].second.size(); k++) {

                cout << rules[j].second[k] << " ";
            }
            float conf = get_confidence(rules[j], transactions);
            float lift = get_lift(rules[j], transactions);
            cout << " confidence: "<< conf;

            if (conf >= confident)
                cout << " Strong rule ";
            

            cout << " Support : " << freq_support;

            cout << " Lift : " << lift;

            cout << endl;
            cout << endl;
        }




    }

    return 0;
}
