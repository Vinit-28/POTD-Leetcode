// Problem Link : https://leetcode.com/problems/string-matching-in-an-array/description/


// Solution //
using ll = long long;
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( i!=j && helper(words[i], words[j]) ){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }

private:
    bool helper(string a, string b){
        if( a.length() > b.length() ) return false;
        ll ahash = 0;
        ll bhash = 0;
        int alen = a.length();
        int blen = b.length();
        ll RADIX = 33;
        ll MOD = 1e9+7;
        ll MAX_RADIX = 1;
        ll PREV_MAX_RADIX = 1;
        auto isSame = [&](int idx)->bool{
            int i = 0, j = idx;
            while( i<alen ){
                if( a[i++] != b[j++] ) return false;
            }
            return true;
        };
        for(int idx=alen-1; idx>=0; idx--){
            ahash = (ahash + (((a[idx]-'a')*MAX_RADIX)%MOD))%MOD;
            bhash = (bhash + (((b[idx]-'a')*MAX_RADIX)%MOD))%MOD;
            PREV_MAX_RADIX = MAX_RADIX;
            MAX_RADIX = (MAX_RADIX * RADIX)%MOD;
        }
        if( ahash == bhash && isSame(0) ) return true;
        for(int idx=alen; idx<blen; idx++){
            int toRemove = idx-alen;
            ll lastCharHash = ((b[toRemove]-'a')*PREV_MAX_RADIX)%MOD;
            bhash = (bhash - lastCharHash + MOD)%MOD;
            bhash = (bhash * RADIX)%MOD;
            bhash = (bhash + (b[idx]-'a'))%MOD;
            if( ahash == bhash && isSame(toRemove+1) ) return true;
        }
        return false;
    }
};