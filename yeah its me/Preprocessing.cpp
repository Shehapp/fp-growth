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



unordered_map<string, int> get_item_frequencies(const vector<vector<string>>& transactions)
{

    unordered_map<string, int> item_freq;

    for (const auto& transaction : transactions)
    {
        unordered_set<string> uniqueItems(transaction.begin(), transaction.end());
        for (const auto& item : uniqueItems)
        {
            item_freq[item]++;
        }
    }

    return item_freq;
}

vector<freq> get_c1_frequent(const vector<vector<string>>& transactions, int support)
{

    unordered_map<string, int> item_freq = get_item_frequencies(transactions);
    vector<freq> c1_frequent;

    for (auto it = item_freq.begin(); it != item_freq.end(); ++it)
    {
        const std::string& item = it->first;       // Key (item)
        int frequency = it->second;                // Value (frequency)

        if (frequency >= support)
        {
            c1_frequent.push_back({ item, frequency });
        }
    }
    std::sort(c1_frequent.begin(), c1_frequent.end(), [](const freq& a, const freq& b) {
        return a.frequent > b.frequent;
        });


    return c1_frequent;
}

vector<vector<string>> rebuild_transactions(const vector<vector<string>>& transactions, const vector<freq>& c1_frequent, int support)
{
    vector<vector<string>> new_transactions;
    unordered_map<string, int> item_freq = get_item_frequencies(transactions);

    for (const auto& transaction : transactions)
    {
        vector<string> sorted_transaction = transaction;


        sort(sorted_transaction.begin(), sorted_transaction.end(),
            [&c1_frequent](const string& a, const string& b) {
                auto find_freq = [&c1_frequent](const string& item) {
                    auto it = find_if(c1_frequent.begin(), c1_frequent.end(),
                        [item](const freq& f) { return f.item == item; });
                    return (it != c1_frequent.end()) ? it->frequent : 0;
                };

                return find_freq(a) > find_freq(b);
            });



        unordered_map<string, int>already_found;
        for (auto& item : sorted_transaction)
        {
            already_found[item]++;
            if (item_freq[item] < support || already_found[item]>1)
            {
                item.clear();
            }
        }

        sorted_transaction.erase(remove(sorted_transaction.begin(), sorted_transaction.end(), ""), sorted_transaction.end());

        new_transactions.push_back(sorted_transaction);
    }

    return new_transactions;
}

