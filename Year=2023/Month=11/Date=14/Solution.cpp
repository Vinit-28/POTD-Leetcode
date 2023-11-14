// Problem Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/


// Solution //
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Declaration //
        int n = s.length(), ans = 0;
        int firstLastOccur[26][2];
        // Initialization //
        memset(firstLastOccur, -1, sizeof(firstLastOccur));
        for(int i=0;i<n;i++){
            if( firstLastOccur[s[i]-'a'][0] == -1 ){
                firstLastOccur[s[i]-'a'][0] = i;
            } else{
                firstLastOccur[s[i]-'a'][1] = i;
            }
        }
        // Main Logic //
        for(int i=0;i<26;i++){
            if( firstLastOccur[i][0] != -1 && firstLastOccur[i][1] != -1 ){
                int start = firstLastOccur[i][0];
                int end = firstLastOccur[i][1];
                ans += getUniqueCharsCount(s, start, end);
            }
        }

        return ans;
    }

    // Method to get the count of unique characters between two indexes //
    int getUniqueCharsCount(string &s, int start, int end){
        int hmap[26] = {0};
        int count = 0;
        for(int i=start+1;i<end;i++){
            count += ++hmap[s[i]-'a'] == 1? 1 : 0;
        }
        return count;
    }
};