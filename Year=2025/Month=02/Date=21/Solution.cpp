// Problem Link : https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/


// Solution //
class FindElements {
private:
    unordered_set<int> st;
public:
    FindElements(TreeNode* root) {
        DFS(root, 0);
    }
    
    bool find(int target) {
        return (bool)st.count(target);
    }
private:
    void DFS(TreeNode *node, int val){
        if( node ){
            st.insert(val);
            DFS(node->left, val*2+1);
            DFS(node->right, val*2+2);
        }
    }
};