// Problem Link : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/


// Solution //
class TrieNode{
public:
    TrieNode *childs[26];
    int prefixSuffixMatchCount;
    TrieNode(){
        for(int i=0; i<26; i++) this->childs[i] = NULL;
        this->prefixSuffixMatchCount = 0;
    }
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        this->root = new TrieNode();
    }

    int insertWord(string &word, vector<int> &zValues){
        int zLen = zValues.size();
        int wordLen = word.size();
        TrieNode *node = root;
        int countMatch = 0;
        for(int idx=0; idx<wordLen; idx++){
            int chIdx = word[idx]-'a';
            if( node->childs[chIdx] == NULL ){
                TrieNode *newNode = new TrieNode();
                node->childs[chIdx] = newNode;
            }
            node = node->childs[chIdx];
            countMatch = node->prefixSuffixMatchCount;
            // Increment the node's prefixSuffixMatchCount only if the current string is having
            // the prefix(0...idx) same as suffix.
            if( zValues[zLen-idx-1] == (idx+1) ){ 
                node->prefixSuffixMatchCount += 1;
            }
        }
        return countMatch;
    }
};

class Solution {
private:
    vector<int> getZValues(string s){\
        int n = s.length();
        int left = 0, right = 0;
        vector<int> zValues(n, 0);
        for(int idx=1; idx<n; idx++){
            if( idx > right ){
                left = right = idx;
                while( right < n && s[right] == s[right-left] ){
                    right += 1;
                }
                zValues[idx] = right - left;
                right -= 1;
            } else{
                if( (zValues[idx-left]+idx) >= right ){
                    left = idx;
                    while( right < n && s[right] == s[right-left] ){
                        right += 1;
                    }
                    zValues[idx] = right - left;
                    right -= 1;
                } else{
                    zValues[idx] = zValues[idx-left];
                }
            }
        }
        return zValues;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Trie trie;
        int ans = 0;
        int totalWords = words.size();
        for(int idx=totalWords-1; idx>=0; idx--){
            auto &word = words[idx];
            auto zValues = getZValues(word+"#"+word);
            ans += trie.insertWord(word, zValues);
        }
        return ans;
    }
};