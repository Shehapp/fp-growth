#include "yeah its me/tree.h"

int main() {

    // preprocess the transaction table 
    vector<vector<string>> transactions = read_input(); //@ali

    // read min_support and conf from user
    // min_support var in preprocessing pack
    int confident,min_support;
    cin>>min_support>>confident;
    set_support(min_support);


     // get frequent items l1
    vector<freq> c1Frequent = get_c1_frequent(transactions); //@anas
    //transactions w ordered item set
    transactions = rebuild_transactions(transactions, c1Frequent); //abdo

    //build the tree
    Tree tree = build_Tree(transactions); //@tarek

    // get conditional pattern base
    map<string,vector<vector<string>>>conditional_pattern_base = get_cond_pattern_base(tree); //@shehapoo

    // get all c1Frequent :)
    vector<vector<string>>frequents;
    vector<string>curPath;
    get_all_freq(c1Frequent, conditional_pattern_base, &frequents, curPath); //@shehapoo


    cout<<"its worked\n";
}
