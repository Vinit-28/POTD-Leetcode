// Problem Link : https://leetcode.com/problems/count-vowel-strings-in-ranges/description/


// Solution //
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int qLen = queries.size();
        vector<int> prefixSum(n, 0);
        vector<int> answers(qLen);
        for(int idx=0; idx<n; idx++){
            int add = (isVowel(words[idx][0]) && isVowel(words[idx].back()));
            prefixSum[idx] = add;
            prefixSum[idx] += idx>0? prefixSum[idx-1] : 0;
        }

        for(int idx=0; idx<qLen; idx++){
            int l = queries[idx][0];
            int r = queries[idx][1];
            int count = l==0? prefixSum[r] : prefixSum[r] - prefixSum[l-1];
            answers[idx] = count;
        }
        return answers;
    }

private:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
};