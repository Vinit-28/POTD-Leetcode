// Problem Link : https://leetcode.com/problems/number-of-good-pairs/description/


// Solution //
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> hmap;
        int ans = 0;
        for(auto &ele : nums){
            hmap[ele] += 1;
        }
        for(auto &p : hmap){
            ans += getCombinations(p.second);
        }
        return ans;
    }

    int getCombinations(int n){
        n-=1;
        return (n * (n+1))/2;
    }
};