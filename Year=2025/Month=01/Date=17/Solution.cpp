// Problem Link : https://leetcode.com/problems/neighboring-bitwise-xor/description/


// Solution //
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return validate(derived, 0) || validate(derived, 1);
    }
private:
    bool validate(vector<int> &arr, int val){
        int n = arr.size();
        int initial = val;
        for(int idx=0; idx<n; idx++){
            val = val xor arr[idx];
        }
        return initial == val;
    }
};
