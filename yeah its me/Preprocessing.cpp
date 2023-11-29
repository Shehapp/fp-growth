//
// Created by shehap on 11/26/2023.
//

#include "Preprocessing.h"
int support;

void set_support(int min_support){
    support = min_support;
}

    vector<vector<string>> read_input() {
        vector<vector<string>> transactions;
        //TODO:[1] read transactions from xlsx file and return transactions
        // @ali



        return transactions;
    }


    vector<freq> get_c1_frequent(
            const vector<vector<string>>& transactions) {
        vector<freq> c1_frequent;
        //TODO:[2] return array of string and its frequent. must be sorted by frequent
        // @anas

        return c1_frequent;
    }


    vector<vector<string>> rebuild_transactions(
            const vector<vector<string>>& transactions,
            const vector<freq>& c1_frequent
    ) {
        vector<vector<string>> new_transactions;
        //TODO:[3] sort each transaction by c1_frequent and erase not frequent items
        // @abdo

        return new_transactions;
    }

