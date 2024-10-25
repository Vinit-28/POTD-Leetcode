// Problem Link : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/


// Solution //
class TrieNode{
public:
    string data;
    bool isPathEnd;
    map<string, TrieNode*> childs;
    TrieNode(string data){
        this->data = data;
        this->isPathEnd = false;
        this->childs = map<string, TrieNode*>();
    }
};

class Trie{
private:
    TrieNode *root;
    TrieNode* getOrCreateNode(TrieNode *node, string &value){
        if( node->childs.find(value) == node->childs.end() ){
            TrieNode *newNode = new TrieNode(value);
            node->childs[value] = newNode;
        }
        return node->childs[value];
    }
public:
    Trie(){
        root = new TrieNode("");
    }

    void insertFullPath(string &path){
        string subPath = "";
        TrieNode *node = root;
        int n = path.size();
        for(int idx=1; idx<n; idx++){
            auto &ch = path[idx];
            if( ch == '/' ){
                node = getOrCreateNode(node, subPath);
                subPath = "";
            } else{
                subPath += ch;
            }
        }
        node = getOrCreateNode(node, subPath);
        node->isPathEnd = true;
    }

    vector<string> findAnswer(){
        vector<string> ans;
        DFS(root, "", ans);
        return ans;
    }

    void DFS(TrieNode *node, string path, vector<string> &ans){
        if( node->isPathEnd ){
            ans.push_back(path);
        } else{
            for(auto [data, child] : node->childs){
                DFS(child, path+"/"+data, ans);
            }
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for(auto &path : folder){
            trie.insertFullPath(path);
        }
        return trie.findAnswer();
    }
};