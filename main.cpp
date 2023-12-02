// Fp-growth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "yeah its me/extraction.h"
#include "yeah its me/tree.h"
#include <iostream>

using namespace std;



void print_tree(const Node* root, int depth = 0) {
    // Print indentation based on depth
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    // Print node information
    std::cout << root->name << " (" << root->freq << ")\n";

    // Recursively print children
    for (const auto &child: root->child) {
        print_tree(child, depth + 1);
    }
}

int main() {
    cout << "Enter min support and confident : " << endl;
    int min_support;
    float confident;
    cin >> min_support >> confident;
    set_support(min_support);
    cout << endl;

//    vector<vector<string>> transactions = read_input("J:\\college\\fp-growth-implementation\\data\\Horizontal_Format.csv"); //@tarek
    vector<vector<string>> transactions = read_input("J:\\college\\fp-growth-implementation\\data\\Vertical_Format.csv"); //@abdo

    freopen("J:\\college\\fp-growth-implementation\\data\\result.txt", "w", stdout);

    cout << "Transactions : " << endl;
    for (int i = 0; i < transactions.size(); i++) {

        for (int j = 0; j < transactions[i].size(); j++) {

            cout << transactions[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;




    // get frequent items l1
    vector<freq> c1Frequent = get_c1_frequent(transactions, min_support); //@anas
    //transactions w ordered item set
    transactions = rebuild_transactions(transactions, c1Frequent, min_support); //abdo


    cout << "\nc1 frequent " << endl;

    for (auto &i: c1Frequent) {

        cout << i.item << " " << i.frequent << endl;

    }


    cout << "\nRebuilt Transactions:" << endl;
    for (auto &transaction: transactions) {
        for (int j = 0; j < transaction.size(); j++) {
            cout << transaction[j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    //build the tree
    Tree tree = build_Tree(transactions); //@tarek

    cout << "FP-Tree" << endl;

    print_tree(tree.root);

    cout << endl;


    // get conditional pattern base
    map<string, vector<vector<string>>> conditional_pattern_base = get_cond_pattern_base(tree); //@shehapoo



    // get all c1Frequent :)
    vector<vector<string>> frequents;
    vector<string> curPath;
    get_all_freq(c1Frequent, conditional_pattern_base, &frequents, curPath, min_support); //@shehapoo


    //get freq for all frequent items 
    cout << "Frequent item sets : " << endl;

    for (auto &frequent: frequents) {
        for (int j = 0; j < frequent.size(); j++) {
            cout << frequent[j] << " ";
        }
        cout << " (frequency : " << get_frequency(frequent, transactions) << " ) " << endl;;

    }
    cout << endl;



    //get the confidence of each rule 
    cout << "RULES confidence :" << endl;
    for (const auto &frequent: frequents) {

        vector<pair<vector<string>, vector<string>>> rules;

        rules = get_rules(frequent);
        float freq_support = get_support(frequent, transactions);

        //for each rule get the confidence 
        for (auto &rule: rules) {


            for (int k = 0; k < rule.first.size(); k++) {

                cout << rule.first[k] << " ";
            }
            cout << " --> ";
            for (int k = 0; k < rule.second.size(); k++) {

                cout << rule.second[k] << " ";
            }
            float conf = get_confidence(rule, transactions);
            float lift = get_lift(rule, transactions);
            cout << " confidence: " << conf;

            if (conf >= confident)
                cout << " Strong rule ";


            cout << " Support : " << freq_support;

            cout << " Lift : " << lift;

            cout << endl;
        }


    }

    freopen("CON", "w", stdout);
    cout << "Done, check result.txt for output\n";
    return 0;
}
