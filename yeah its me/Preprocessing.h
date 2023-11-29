//
// Created by shehap on 11/26/2023.
//

#include <bits/stdc++.h>
using namespace std;

void set_support(int min_support);
struct freq{
    string item;
    string frequent;

    bool operator<(const freq& other) const {
        return frequent < other.frequent;
        // You can customize the comparison based on your needs
    }
};

vector<vector<string>> read_input();
vector<freq> get_c1_frequent(
            const vector<vector<string>>& transactions);
vector<vector<string>> rebuild_transactions(
        const vector<vector<string>>& transactions,
        const vector<freq>& c1_frequent
);


