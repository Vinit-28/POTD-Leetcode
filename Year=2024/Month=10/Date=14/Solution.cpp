// Problem Link : https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/


// Solution //
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        long long int ans = 0;
        for(auto &ele : nums) pq.push(ele);
        while(k>0){
            auto ele = pq.top(); pq.pop();
            ans += ele;
            pq.push(ceil(double(double(ele)/3)));
            // cout<<double(double(ele)/3)<<" >> "<<ceil(double(double(ele)/3))<<endl;
            k-=1;
        }
        return ans;
    }
};