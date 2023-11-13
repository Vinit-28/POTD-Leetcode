// Problem Link : https://leetcode.com/problems/sort-vowels-in-a-string/description/


// Solution //
class Solution {
public:
    bool isVowel(char ch){
        ch = ch>='A' && ch<='Z'? ch+32 : ch;
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    string sortVowels(string s) {
        string vowels = "", t = s;
        vector<int> vowelIdxs;
        int n = s.length(), idx = 0;
        // Findind the vowels & their indexes //
        for(int i=0;i<n;i++){
            if( isVowel(s[i]) ){
                vowels += s[i];
                vowelIdxs.push_back(i);
            }
        }
        // Sorting the vowels /
        sort(vowels.begin(), vowels.end());

        // Storing the vowels in ascending order //
        for(auto &vowel : vowels){
            t[vowelIdxs[idx++]] = vowel;
        }
        // Returing the answer //
        return t;
    }
};