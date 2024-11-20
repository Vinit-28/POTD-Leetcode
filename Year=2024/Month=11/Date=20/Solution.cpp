// Problem Link : https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/


// Solution //
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        string str = s + s;
        int minWind = 1e9;
        int mpp[3] = {0};
        int right = 0;
        if( k==0 ) return 0;
        for(; right<n; right++){
            if( mpp[0] >= k && mpp[1] >= k && mpp[2] >= k ){
                minWind = right;
                break;
            }
            mpp[str[right]-'a'] += 1;
        }
        mpp[str[0]-'a'] -= 1;
        for(int left=1; left<n; left++){
            while( (right < (n+n) && (right-left+1) <= n && (mpp[0]<k || mpp[1]<k || mpp[2]<k)) || right < n ){
                mpp[str[right]-'a'] += 1;
                right += 1;
            }
            if( mpp[0] >= k && mpp[1] >= k && mpp[2] >= k ){
                int windLen = right - left;
                minWind = min(minWind, windLen);
            }
            mpp[str[left]-'a'] -= 1;
        }
        return minWind==1e9? -1 : minWind;
    }
};