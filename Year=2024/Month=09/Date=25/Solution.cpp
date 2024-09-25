// Problem Link : https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/


// Solution //
class TrieNode{
public:
    char data;
    int words;
    TrieNode *childs[26];
    TrieNode(char data){
        this->data = data;
        this->words = 0;
        for(int i=0; i<26; i++) this->childs[i] = NULL;
    }
};

class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('~');
    }

    void insertWord(string &word){
        TrieNode *node = root;
        for(auto &ch : word){
            if( !node->childs[ch-'a'] ){
                TrieNode *newNode = new TrieNode(ch);
                node->childs[ch-'a'] = newNode;
            }
            node = node->childs[ch-'a'];
            node->words += 1;
        }
    }

    int countPrefixMatch(string &word){
        TrieNode *node = root;
        int count = 0;
        for(auto &ch : word){
            node = node->childs[ch-'a'];
            count += node->words;
        }
        return count;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> ans;
        for(auto &word : words){
            trie.insertWord(word);
        }
        for(auto &word : words){
            ans.push_back(trie.countPrefixMatch(word));
        }
        return ans;
    }
};