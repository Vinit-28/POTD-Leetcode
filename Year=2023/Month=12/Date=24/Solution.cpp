// Problem Link : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/


// Solution //
class Solution {
public:
    int minOperations(string s) {
        int ans = helper(s);
        s[0] = s[0]=='0'? '1' : '0';
        ans = min(ans, helper(s)+1);
        return ans;
    }

    int helper(string s){
        int n = s.length();
        int ops = 0; 
        for(int i=1;i<n;i++){
            if( s[i] == s[i-1] ){
                s[i] = s[i-1]=='0'? '1' : '0';
                ops += 1;
            }
        }
        return ops;
    }
};