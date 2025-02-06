// Problem Link : https://leetcode.com/problems/tuple-with-same-product/description/


// Solution //
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int product = nums[i] * nums[j];
                mpp[product] += 1;
            }
        }
        for(auto [product, freq]: mpp){
            int totalPairs = (freq * (freq-1))/2;
            count += (totalPairs * 8);
        }
        return count;
    }
};