//
// Created by shehap on 11/26/2023.
//

#include "tree.h"



Tree build_Tree(
        const vector<vector<string>>& transactions
) {
/*TODO:[4] build Tree obj, every node has its freq and next level nodes
 * please use while loop to add Nodes
*/
    Tree myTree;
    for (const auto& transaction : transactions)
    {
        Node* currentNode = myTree.root;

        for (const auto& nodeName : transaction)
        {

            //cout<<nodeName<<endl;

            Node* childNode = nullptr;
            for (const auto& child : currentNode->child)
            {
                    //cout<<currentNode->child.size()<<" NC"<<endl;
                if (child->name == nodeName)
                {
                    //cout<<nodeName<<"----"<<child->name<<endl;
                    childNode = child;
                    //break;
                }
            }

            if (childNode)
            {
                childNode->freq++;
                currentNode = childNode;
            }
            else
            {
                //cout<<nodeName<<"hmm"<<endl;
                Node* newNode = new Node;
                newNode->name = nodeName;
                newNode->freq = 1;
                currentNode->child.push_back(newNode);
                //currentNode = newNode;
            }

        }
    }

    return myTree;
    


}

map<string,vector<Pattern_base>> get_cond_pattern_base(Tree tree){
    map<string,vector<Pattern_base>> base;
    /*TODO:[5] use Tree obj, to extract conditional pattern base
     * please use helper function to do this*/
    vector<string>curPath;
    auto dfs=[&](auto &&self,Node *curNode)->void {
        if(!curPath.empty()){
            Pattern_base patternBase;
            patternBase.frequent=curNode->freq;
            patternBase.items=curPath;
            base[curNode->name].push_back(patternBase);
        }
        if(curNode->name!="root")
            curPath.push_back(curNode->name);

        for(auto node:curNode->child){
            self(self,node);
        }
        if(curNode->name!="root")
            curPath.pop_back();
    };
    dfs(dfs,tree.root);
    return base;
}

