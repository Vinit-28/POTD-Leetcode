// Problem Link : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/


// Solution //
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;
        DFS(root, distance, pairs);
        return pairs;
    }

    map<TreeNode*, int> DFS(TreeNode *node, int &distance, int &pairs){
        if( node ){
            map<TreeNode*, int> allLeafs; // {leafNode: distanceTillCurrentNode} //
            // Node is itself a Leaf Node //
            if( !node->left && !node->right ){
                allLeafs[node] = 0;
            } else{
                auto leftLeafs = DFS(node->left, distance, pairs);
                auto rightLeafs = DFS(node->right, distance, pairs);
                // Identifying the valid pairs b/w left leafs & right leafs //
                for(auto &ll : leftLeafs){
                    int d1 = ll.second + 1;
                    for(auto &rl : rightLeafs){
                        int d2 = rl.second;
                        if( (d1 + d2 + 1) <= distance ){
                            pairs += 1;
                        }
                    }
                }
                // Merging left & rigth leafs //
                for(auto &ll: leftLeafs){
                    allLeafs[ll.first] = ll.second+1;
                }
                for(auto &rl: rightLeafs){
                    allLeafs[rl.first] = rl.second+1;
                }
            }
            return allLeafs;
        }
        return {};
    }
};