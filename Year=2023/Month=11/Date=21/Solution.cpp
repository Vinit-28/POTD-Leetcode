// Problem Link : https://leetcode.com/problems/count-nice-pairs-in-an-array/description/


// Solution //
class Solution {
public:

    int getReverse(int &ele){
        string str = to_string(ele);
        reverse(str.begin(), str.end());
        return stoi(str);
    }

    int countNicePairs(vector<int>& nums) {
        map<int, int> hmap;
        int ans = 0;
        long MOD = 1e9+7;
        for(auto &ele : nums){
            int rev = getReverse(ele);
            int diff = ele - rev;
            ans = (ans + hmap[diff])%MOD;
            hmap[diff] = (hmap[diff] + 1)%MOD;
        }
        return ans;
    }
};
