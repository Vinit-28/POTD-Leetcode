// Problem Link : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/


// Solution //
using ll = long long;

class Solution {
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        queue<TreeNode*> q;
        q.push(root);
        
        // BFS //         
        while( q.empty()==false ){
            int size = q.size();
            ll sum = 0;
            while( size-- > 0 ){
                auto node = q.front(); q.pop();
                sum += node->val;
                if( node->left ) q.push(node->left);
                if( node->right ) q.push(node->right);
            }
            if( pq.size() == k && pq.top() < sum ) pq.pop();
            if( pq.size() < k ) pq.push(sum);
        }
        return pq.size()<k? -1 : pq.top();
    }
    
};