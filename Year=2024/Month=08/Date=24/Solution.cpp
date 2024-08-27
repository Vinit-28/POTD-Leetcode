// Problem Link : https://leetcode.com/problems/find-the-closest-palindrome/description/



// Solution //
class Solution {
public:
    using ll = long long;
    string nearestPalindromic(string n) {
        vector<ll> possibles;
        if( n.length() > 1 ) possibles.push_back(pow(10, n.length()-1)-1); // 99..9..99 //
        possibles.push_back(pow(10, n.length())+1); // 10..0..01 //
        int mid = (n.length()&1)? n.length()/2 : n.length()/2-1;
        string s = n.substr(0, mid+1);
        for(auto &inc : {-1,0,1}){
            ll firstHalf = stoll(s);
            firstHalf += inc;
            string firstHalfStr = to_string(firstHalf);
            if( firstHalf >= 0 ){
                string secondHalfStr = (n.length()&1)? firstHalfStr.substr(0, mid) : firstHalfStr;
                reverse(begin(secondHalfStr), end(secondHalfStr));
                string newNum = firstHalfStr + secondHalfStr;
                if( newNum != n ) possibles.push_back(stoll(newNum));
            }
        }
        ll minDiff = 1e18;
        ll num = stoll(n);
        string ans = "-1";
        for(auto &val : possibles){
            ll diff = abs(val - num);
            if( diff < minDiff ){
                minDiff = diff;
                ans = to_string(val);
            }
        }
        return ans;
    }
};