// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/


// Solution //
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        int ops = 0;
        que.push(root);
        while( que.empty()==false ){
            vector<int> values;
            int size = que.size();
            while( size-- > 0 ){
                auto node = que.front(); que.pop();
                values.push_back(node->val);
                if( node->left ) que.push(node->left);
                if( node->right ) que.push(node->right);
            }
            
            ops += findMinSwaps(values);
        }
        return ops;
    }
    
private:
    int findMinSwaps(vector<int> &values){
        int n = values.size();
        int swaps = 0;
        vector<int> sortedValues = values;
        sort(begin(sortedValues), end(sortedValues));
        unordered_map<int,int> valueToIdx;
        for(int i=0; i<n; i++){
            valueToIdx[values[i]] = i;
        }
        for(int idx=0; idx<n; idx++){
            int value = values[idx];
            int expValue = sortedValues[idx];
            if( value != expValue ){
                int expValueIdx = valueToIdx[expValue];
                swap(values[idx], values[expValueIdx]);
                swaps += 1;
                valueToIdx[expValue] = idx;
                valueToIdx[value] = expValueIdx;
            }
        }
        return swaps;
    }
};