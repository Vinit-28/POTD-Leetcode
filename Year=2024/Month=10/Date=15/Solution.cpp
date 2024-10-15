// Problem Link : https://leetcode.com/problems/separate-black-and-white-balls/description/


// Solution //
using ll = long long;
class Solution {
public:
    long long minimumSteps(string s) {
        ll ans = 0;
        ll count = 0;
        for(auto &ch : s){
            if(ch == '0'){
                ans += count;
            } else{ 
                count += 1; 
            }
        }
        return ans;
    }
};