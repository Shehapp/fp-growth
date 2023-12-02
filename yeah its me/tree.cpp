//
// Created by shehap on 11/26/2023.
//

#include "tree.h"



Tree build_Tree(
    const vector<vector<string>>& transactions
) {
    /*TODO:[4] build Tree obj, every node has its freq and next level nodes
     * please use while loop to add Nodes
     * @tarek
    */
    Tree myTree;
    for (const auto& transaction : transactions)
    {
        Node* currentNode = myTree.root;

        for (const auto& nodeName : transaction)
        {


            Node* childNode = nullptr;
            for (const auto& child : currentNode->child)
            {
                if (child->name == nodeName)
                {
                    childNode = child;
                    break;
                }
            }

            if (childNode)
            {
                childNode->freq++;
                currentNode = childNode;
            }
            else
            {
                Node* newNode = new Node;
                newNode->name = nodeName;
                newNode->freq = 1;
                currentNode->child.push_back(newNode);
                currentNode = newNode;
            }

        }
    }

    return myTree;



}

map<string, vector<vector<string>>> get_cond_pattern_base(Tree tree) {
    map<string, vector<vector<string>>> base;
    /*TODO:[5] use Tree obj, to extract conditional pattern base
     * please use helper function to do this
     * @shehapoo
     * */
    vector<string>curPath;
    auto dfs = [&](auto&& self, Node* curNode)->void {
        if (!curPath.empty()) {
            for (int i = 0; i < curNode->freq; ++i) {
                base[curNode->name].push_back(curPath);
            }
        }
        if (curNode->name != "root")
            curPath.push_back(curNode->name);

        for (auto node : curNode->child) {
            self(self, node);
        }
        if (curNode->name != "root")
            curPath.pop_back();
    };
    dfs(dfs, tree.root);
    return base;
}

void get_all_freq(const vector<freq>& c1Frequent,
    map<string, vector<vector<string>>>conditional_pattern_base,
    vector<vector<string>>* frequents,
    vector<string>curPath,int support) {
    /*TODO:[6] get all frequent
         * @shehapoo
         * */
    for (const auto& i : c1Frequent) {
        curPath.push_back(i.item);
        sort(curPath.begin(), curPath.end());
        frequents->push_back(curPath);

        vector<freq>new_c1Frequent =
            get_c1_frequent(conditional_pattern_base[i.item],support);

        if (!new_c1Frequent.empty()) {

            vector<vector<string>> transactions = rebuild_transactions(conditional_pattern_base[i.item], c1Frequent,support);

            Tree tree = build_Tree(transactions);

            get_all_freq(new_c1Frequent,
                get_cond_pattern_base(tree),
                frequents,
                curPath,support);
        }
        curPath.erase(std::find(curPath.begin(), curPath.end(), i.item));

    }


}