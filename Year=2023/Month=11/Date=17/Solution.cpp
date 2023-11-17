// Problem Link : https://leetcode.com/problems/find-unique-binary-string/description/


// Solution //
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), idx = 0;
        string ans(n, '!');
        sort(nums.begin(), nums.end());
        for(auto &s : nums){
            ans[idx++] = s[idx]=='0'? '1' : '0';
        }
        return ans;
    }
};