#include "yeah its me/preprocessing.h"
#include "yeah its me/tree.h"

int main() {

    // preprocess the transaction table
    vector<vector<string>> transactions = read_input();
    vector<freq> frequent = get_c1_frequent(transactions);
    //transactions w ordered item set
    transactions = rebuild_transactions(transactions, frequent);

    //build the tree
    Tree tree = build_Tree(transactions);
    // get conditional pattern base
    map<string,Pattern_base>conditional_pattern_base = get_cond_pattern_base(tree);


    cout<<"its works\n";
}
