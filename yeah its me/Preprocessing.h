// Created by shehap on 11/26/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void set_support(int min_support);
struct freq {
    string item;
    int frequent;

    bool operator<(const freq& other) const {
        return frequent < other.frequent;
        
    }
};

vector<vector<string>> read_input();
unordered_map<string, int>  get_item_frequencies(const vector<vector<string>>& transactions);
vector<freq> get_c1_frequent(
    const vector<vector<string>>& transactions,int support);
vector<vector<string>> rebuild_transactions(
    const vector<vector<string>>& transactions,
    const vector<freq>& c1_frequent,int support
);


