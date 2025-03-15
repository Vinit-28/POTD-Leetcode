// Problem Link : https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll countOfSubstrings(string word, int k) {
        ll ans = 0;
        int n = word.size();
        int right = 0;
        int con = 0;
        int mpp[26] = {0};
        int startIdx = -1;
        vector<int> vowelsAhead(n+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            vowelsAhead[idx] = isVowel(word[idx])? vowelsAhead[idx+1] + 1 : 0;
        }
        for(int left=0; left<n; left++){
            // Need for Vowels & Consonants //
            while( right<n && (containsEveryVowel(mpp)==false || con<k) ){
                mpp[word[right]-'a'] += 1;
                isVowel(word[right++])? 0 : con++;
            }
            if( con == k && containsEveryVowel(mpp) ){
                ans += vowelsAhead[right]+1;
            }
            !isVowel(word[left])? --con : 0;
            mpp[word[left]-'a']-=1;
        }  
        return ans;
    }
private:
    bool isVowel(char &ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    bool containsEveryVowel(int mpp[]){
        return mpp['a'-'a'] && mpp['e'-'a'] && mpp['i'-'a'] && mpp['o'-'a'] && mpp['u'-'a'];
    }
};