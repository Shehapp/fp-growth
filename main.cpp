#include "yeah its me/preprocessing.h"
#include "yeah its me/tree.h"

int main() {

    // preprocess the transaction table
    vector<vector<string>> transactions = read_input();
    vector<freq> frequent = get_c1_frequent(transactions);
    transactions = rebuild_transactions(transactions, frequent);

    //build the tree
    Tree tree = build_Tree(transactions);
    cout<<'\n';
}
