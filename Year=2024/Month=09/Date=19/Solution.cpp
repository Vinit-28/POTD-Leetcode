// Problem Link : https://leetcode.com/problems/largest-number/description/


// Solution //
class Solution {
private:
    bool isAllZero(string &num){
        for(auto &d : num) if( d > '0' ) return false;
        return true;
    }

public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(begin(nums), end(nums), [](int a, int b){
            string stra = to_string(a);
            string strb = to_string(b);
            return (stra+strb) > (strb+stra);
        });
        for(auto &num: nums) ans += to_string(num);
        return isAllZero(ans)? "0" : ans;
    }
};