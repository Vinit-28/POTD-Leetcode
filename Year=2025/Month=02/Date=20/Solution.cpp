// Problem Link : https://leetcode.com/problems/find-unique-binary-string/description/


// Solution //
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int idx=0; idx<n; idx++){
            ans += (nums[idx][idx]=='1'? '0' : '1');
        }
        return ans;
    }
};