// Problem Link : https://leetcode.com/problems/number-of-atoms/description/


// Solution //
class Solution {
public:
    string countOfAtoms(string formula) {
        int idx = 0;
        auto mpp = helper(formula, idx);
        string ans = "";
        for(auto &p : mpp){
            ans += p.first;
            if( p.second > 1 ){
                ans += to_string(p.second);
            }
        }
        return ans;
    }

    map<string, int> helper(string &s, int &idx){
        map<string, int> mpp;
        string atom = "";
        int count = 0;
        while( idx < s.length() ){
            if( s[idx] >= 'A' && s[idx] <= 'Z' ){ // New Atom //
                if( atom != "" ){
                    mpp[atom] += max(count, 1);
                }
                atom = ""; atom += s[idx];
                count = 0;
            } else if( s[idx] >= 'a' && s[idx] <= 'z' ){ // Same Atom //
                atom += s[idx];
            } else if( s[idx] >= '0' && s[idx] <= '9' ){ // Count of the Atom //
                count = (count*10) + (s[idx]-'0');
            } else if( s[idx] == ')' ){ // Closing the formula //
                break;
            } else if( s[idx] == '(' ){ // Opening of the new formula //
                idx += 1;
                auto mpp1 = helper(s, idx);
                int m = 0;
                idx += 1;
                while( idx<s.length() && s[idx] >= '0' && s[idx] <= '9' ){
                    m = (m*10) + (s[idx]-'0');
                    idx += 1;
                }
                m = max(1, m);
                for(auto &p : mpp1) p.second *= m;
                for(auto &p : mpp1) mpp[p.first] += p.second;
                continue;
            }
            idx += 1;
        }
        if( atom != "" ){
            mpp[atom] += max(count, 1);
        }
        return mpp;
    }
};