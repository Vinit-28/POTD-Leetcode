// Problem Link : https://leetcode.com/problems/validate-binary-tree-nodes/description/


// Solution //
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int parents[n]; memset(parents, -1, sizeof(parents));
        for(int i=0;i<n;i++){
            if( !connect(i, leftChild[i], parents) ) return false;
            if( !connect(i, rightChild[i], parents) ) return false;
        }
        int roots = 0;
        for(int i=0;i<n;i++){
            roots += parents[i]==-1;
        }
        return roots==1;
    }

    bool connect(int u, int v, int parents[]){
        if( v == -1 ) return true;
        int uP = findParent(parents, u);
        int vP = findParent(parents, v);
        if( vP != v || vP == uP ) return false;
        parents[vP] = uP;
        return true;
    }

    int findParent(int parents[], int node){
        if( parents[node] == -1 ){
            return node;
        }
        return parents[node] = findParent(parents, parents[node]);
    }
};