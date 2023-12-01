// Fp-growth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "tree.h"
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
    //vector<vector<string>> transactions = read_input(); //@ali

    // read min_support and conf from user
    // min_support var in preprocessing pack
    int confident, min_support;
    cin >> min_support >> confident;
    set_support(min_support);
    vector<vector<string>> transactions =
    {
        {"M", "O", "N", "K", "E", "Y"},
        {"D", "O", "N", "K", "E", "Y"},
        {"M", "A", "K", "E"},
        {"M", "U", "C", "K", "Y"},
        {"C", "O", "O", "K", "I", "E"}
    };

    /*
    * {
    *  
    * 
    * 
    	{"I1","I2","I3"}
      	{"I2","I3","I4"}
	    {"I4","I5"}
	    {"I1","I2","I4"}
     	{"I1","I2","I3","I5"}
	    {"I1","I2","I3","I4"}
      }
    
    
    */

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

   /* vector<vector<string>> transactions = {
        {"K","E","M","O","Y"},
        {"K","E","O","Y"},
        {"K","E","M"},
        {"K","M","Y"},
        {"K","E","O"},

    };*/
    //build the tree
    Tree tree = build_Tree(transactions); //@tarek

    printTree(tree.root);

    // get conditional pattern base
    map<string, vector<vector<string>>>conditional_pattern_base = get_cond_pattern_base(tree); //@shehapoo

    // get all c1Frequent :)
    vector<vector<string>>frequents;
    vector<string>curPath;
    get_all_freq(c1Frequent, conditional_pattern_base, &frequents, curPath,min_support); //@shehapoo

    for (int i = 0; i < frequents.size(); i++)
    {
        for (int j = 0; j < frequents[i].size(); j++)
        {
            cout << frequents[i][j] << " ";
        }
        cout << endl;
    }
    return 0;


    cout << "its worked\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
