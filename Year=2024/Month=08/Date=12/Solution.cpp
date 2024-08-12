// Problem Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/



// Disjoint Set Union //
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto &ele : nums){
            if( pq.size() < k ){
                pq.push(ele);
            } else if( pq.top() < ele ){
                pq.pop();
                pq.push(ele);
            }
        } 
    }
    
    int add(int val) {
        if( pq.size() < k ){
            pq.push(val);
        } else if( pq.top() < val ){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};