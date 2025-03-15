// Problem Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/


// Solution //
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        int right = 0;
        int mpp[3] = {0};
        for(int left=0; left<n; left++){
            while( right<n && !containsAll3(mpp) ){
                mpp[s[right++]-'a'] += 1;
            }
            if( containsAll3(mpp) ){
                ans += (n-right+1);
            }
            mpp[s[left]-'a'] -= 1;
        }
        return ans;
    }
private:
    bool containsAll3(int mpp[]){
        return mpp[0] && mpp[1] && mpp[2];
    }
};