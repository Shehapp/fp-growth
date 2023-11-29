#include "yeah its me/preprocessing.h"
#include "yeah its me/tree.h"
#include "yeah its me/extraction.h"

int main() {

    // preprocess the transaction table 
    vector<vector<string>> transactions = read_input(); //@ ALI_KHALED
    vector<freq> frequent = get_c1_frequent(transactions); //@ ANAS
    //transactions w ordered item set
    transactions = rebuild_transactions(transactions, frequent); //ABDO SHERIF

    //build the tree
    Tree tree = build_Tree(transactions); //@tarek
    // get conditional pattern base
    map<string,vector<Pattern_base>>conditional_pattern_base = get_cond_pattern_base(tree); //@shehap+tarek 


    cout<<"its worked\n";
}
