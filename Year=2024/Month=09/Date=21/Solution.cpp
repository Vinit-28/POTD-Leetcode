// Problem Link : https://leetcode.com/problems/lexicographical-numbers/description/


// Solution //
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        helper(n, 0, ans);
        return ans;
    }

    void helper(int n, int num, vector<int> &ans){
        for(int d=0; d<=9; d++){
            int newNum = num*10+d;
            if( newNum == 0 ) continue;
            if( newNum > n ) break;
            ans.push_back(newNum);
            helper(n, newNum, ans);
        }
    }
};