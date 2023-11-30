//
// Created by shehap on 11/27/2023.
//

#include "extraction.h"

void generate_combinations(vector<string>& items, int start, vector<string>& current, vector<pair<vector<string>, vector<string>>>& result) {

    /*TODO:[10] get all frequent
         * @Tarek
         * Using bactracking and recursion to get all rules 
         * */

    
    if (current.size() == items.size()) {
        vector<string> first_set, second_set;
        for (int i = 0; i < items.size(); ++i) {
            if (current[i] == "1") {
                first_set.push_back(items[i]);
            }
            else {
                second_set.push_back(items[i]);
            }
        }
        if (!first_set.empty() && !second_set.empty()) {
            result.push_back({ first_set, second_set });
        }
        return;
    }


    current.push_back("1");
    generate_combinations(items, start + 1, current, result);
    current.pop_back();



    current.push_back("0");
    generate_combinations(items, start + 1, current, result);
    current.pop_back();
}





vector<  pair < vector<string>, vector<string>> > get_rules(vector<string>frq_itemset) {
    /*TODO:[7] get all frequent
         * @Tarek
         * */
    vector<  pair < vector<string>, vector<string>> >rules;
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

    for (int i = 0; i < transactions.size(); i++) {
        if (all_of(items.begin(), items.end(), [&transactions, i](const string& item) {

            return find(transactions[i].begin(), transactions[i].end(), item) != transactions[i].end();

            })) {

            frequency++;
        }
    }

    return frequency;

}

float get_support(vector<string>items, vector<vector<string>> transactions) {
    /*TODO:[8] get all frequent
         *@ Abdo sherif
         * */

    return 0;
}


float get_confidence(pair<string, string>rule, vector<vector<string>> transactions) {
    /*TODO:[9] get all frequent
         *@ Anas 
         * */

    return 0;


}