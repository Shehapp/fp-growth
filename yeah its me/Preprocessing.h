//
// Created by shehap on 11/26/2023.
//

#include <bits/stdc++.h>
using namespace std;

struct freq{
    string item;
    string frequent;
};

vector<vector<string>> read_input();
vector<freq> get_c1_frequent(
            vector<vector<string>> transactions
    );
vector<vector<string>> rebuild_transactions(
        vector<vector<string>> transactions,
        const vector<freq>& c1_frequent
);


