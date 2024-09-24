// Problem Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/


// Solution //
class TrieNode{
public:
    char data;
    TrieNode *childs[10];
    TrieNode(char data){
        this->data = data;
        for(int i=0; i<10; i++) childs[i] = NULL;
    }
};

class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('~');
    }

    void insertWord(string word){
        TrieNode *node = root;
        for(auto &ch : word){
            if( !node->childs[ch-'0'] ){
                TrieNode *newNode = new TrieNode(ch);
                node->childs[ch-'0'] = newNode;
            }
            node = node->childs[ch-'0'];
        }
    }

    int getMaxPrefixLength(string word){
        TrieNode *node = root;
        int idx = 0;
        while( idx < word.size() && node->childs[word[idx]-'0'] ){
            node = node->childs[word[idx]-'0'];
            idx += 1;
        }
        return idx;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        int maxPrefixLength = 0;
        for(auto &num : arr1){
            trie.insertWord(to_string(num));
        }
        for(auto &num : arr2){
            maxPrefixLength = max(maxPrefixLength, trie.getMaxPrefixLength(to_string(num)));
        }
        return maxPrefixLength;
    }
};