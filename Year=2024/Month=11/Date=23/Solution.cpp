// Problem Link : https://leetcode.com/problems/rotating-the-box/description/


// Solution //
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ansBox(n, vector<char>(m));
        for(int i=0; i<m; i++){
            int empty = -1;
            for(int j=n-1; j>=0; j--){
                if( box[i][j] == '.' ){
                    empty = empty==-1? j : empty;
                } else if( box[i][j] == '*' ){
                    empty = j-1;
                } else if( empty != -1 ){
                    swap(box[i][j], box[i][empty--]);
                }
            }
        }
        for(int br=m-1,abc=0; br>=0; br--,abc++){
            for(int bc=0,abr=0; bc<n; bc++,abr++){
                ansBox[abr][abc] = box[br][bc];
            }
        }
        return ansBox;
    }
};