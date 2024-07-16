// Problem Link : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/


// Solution //
class Solution {
public:
    int adj[100005][3];
    string getDirections(TreeNode* root, int startValue, int destValue) {
        memset(adj, -1, sizeof(adj));
        string path="";
        // Building the Adjacency List //
        DFS1(root, -1);
        // finding the path from Source to Destination //
        DFS2(startValue, -1, path, destValue);
        return path;
    }

    void DFS1(TreeNode *node, int parent){
        if( node ){
            int left = node->left? node->left->val : -1;
            int right = node->right? node->right->val : -1;
            adj[node->val][0] = parent;
            adj[node->val][1] = left;
            adj[node->val][2] = right;
            DFS1(node->left, node->val);
            DFS1(node->right, node->val);
        }
    }

    bool DFS2(int node, int parent, string &path, int &destValue){
        if( node == destValue ){
            return true;
        } else{
            // Visiting the neighbours //
            for(int idx=0; idx<3; idx++){
                int cn = adj[node][idx];
                char dir = idx==0? 'U' : idx==1? 'L' : 'R';
                if( cn != -1 && cn != parent ){
                    path.push_back(dir);
                    if( DFS2(cn, node, path, destValue) ) return true;
                    path.pop_back();
                }
            }
        }
        return false;
    }
};