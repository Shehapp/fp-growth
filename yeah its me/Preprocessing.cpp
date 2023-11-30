//
// Created by shehap on 11/26/2023.
//

#include "Preprocessing.h"
int support;

void set_support(int min_support)
{
    support = min_support;
}

vector<vector<string>> read_input()
{
    vector<vector<string>> transactions;
    // TODO:[1] read transactions from xlsx file and return transactions
    //  @ali

    return transactions;
}

vector<freq> get_c1_frequent(const vector<vector<string>> &transactions)
{
    vector<freq> c1_frequent;
    bool match = false;
    // TODO:[2] return array of string and its frequent. must be sorted by frequent
    //  @anas
    for (const auto & transaction : transactions)
    {
        for (const auto & j : transaction)
        {
            for (auto & i1 : c1_frequent)
            {
                /* code */
                if (i1.item == j)
                {
                    i1.frequent++;
                    match = true;
                }
            }
            if (match == 0)
            {
                freq f;
                f.item = j;
                f.frequent = 1;
                c1_frequent.push_back(f);
            }
        }
    }
    for (auto i2 = c1_frequent.begin(); i2 != c1_frequent.end(); i2++)
    {
        if (i2->frequent < support)
            c1_frequent.erase(i2);
    }
    sort(c1_frequent.begin(), c1_frequent.end());
    return c1_frequent;
}

vector<vector<string>> rebuild_transactions(const vector<vector<string>> &transactions, const vector<freq> &c1_frequent)
{
    vector<vector<string>> new_transactions;
    // TODO:[3] sort each transaction by c1_frequent and erase not frequent items
    //  @abdo

    for (int t_1 = 0; t_1 < transactions.size(); t_1++)
    {
        for (int t_2 = 0; t_2 < transactions[t_1].size(); t_2++)
        {
            for (const auto& el : c1_frequent)
            {
                if ( transactions[t_1][t_2] == el.item )
                {
                    new_transactions[t_1].push_back(el.item);
                    break;
                }
                
            }
        }
    }

    return new_transactions;
}
