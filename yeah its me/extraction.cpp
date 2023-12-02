//
// Created by shehap on 11/27/2023.
//

#include "extraction.h"

void generate_combinations(vector<string>& items, int start, vector<string>& current, vector<pair<vector<string>, vector<string>>>& result) {

    /*TODO:[10] get all frequent
         * @Tarek
         * Using backtracking and recursion to get all rules
         * */


    if (current.size() == items.size()) {
        vector<string> first_set, second_set;
        for (int i = 0; i < items.size(); ++i) {
            if (current[i] == "1") {
                first_set.push_back(items[i]);
            } else {
                second_set.push_back(items[i]);
            }
        }
        if (!first_set.empty() && !second_set.empty()) {
            result.emplace_back(first_set, second_set);
        }
        return;
    }


    current.emplace_back("1");
    generate_combinations(items, start + 1, current, result);
    current.pop_back();


    current.emplace_back("0");
    generate_combinations(items, start + 1, current, result);
    current.pop_back();
}





// helper function to get all frequent itemset
vector<  pair < vector<string>, vector<string>> > get_rules(vector<string>frq_itemset) {
    /*TODO:[7] get all frequent
         * @Tarek
         * */
    vector<pair<vector<string>, vector<string>>> rules;
    vector<string> current;

    generate_combinations(frq_itemset, 0, current, rules);


    return rules;

}






// get the freq for one or more item together
int get_frequency(vector<string>items, vector<vector<string>> transactions) {
    /*TODO:[7] get all frequent
         * @Tarek 
         * time could be reduced using binary search by sorting the transactions
         * */

    int frequency = 0;

    for (auto & transaction : transactions) {
        if (all_of(items.begin(), items.end(), [&transactions, &transaction](const string &item) {

            return find(transaction.begin(), transaction.end(), item) != transaction.end();

        })) {

            frequency++;
        }
    }

    return frequency;

}


// helper function to calculate support
float get_support(vector<string>items, const vector<vector<string>>& transactions) {
    /*TODO:[8] get all frequent
         *@ Abdo sherif
         * */

    return float(get_frequency(items, transactions)) / float(transactions.size());

}


float get_confidence(pair<vector<string>, vector<string>> rule, vector<vector<string>> transactions) {
    /*TODO:[9] get all frequent
     *@ Anas
     * */

    vector<string> mergedVector(rule.first.begin(), rule.first.end());
    mergedVector.insert(mergedVector.end(), rule.second.begin(), rule.second.end());

    return float(get_frequency(mergedVector, transactions)) / float(get_frequency(rule.first, transactions));
}

float get_lift(pair<vector<string>, vector<string>> rule, const vector<vector<string>>& transactions) {
    /*TODO:[11] get all frequent
     *@ Tarek
     * */

    vector<string> mergedVector(rule.first.begin(), rule.first.end());
    mergedVector.insert(mergedVector.end(), rule.second.begin(), rule.second.end());


    float support_f = get_support(rule.first, transactions);
    float support_s = get_support(rule.second, transactions);
    float support_fs = get_support(mergedVector, transactions);

    if (support_f == 0 || support_s == 0) {

        return 0;
    }

    float lift = (support_fs / (support_f * support_s));

    return lift;

}