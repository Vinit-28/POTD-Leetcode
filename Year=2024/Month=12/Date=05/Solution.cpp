// Problem Link : https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/


// Solution //
class Solution {
public:
    bool canChange(string start, string target) {
        string s1 = "", s2 = "";
        int n = start.size();
        vector<int> idxs1, idxs2;
        for(int i=0; i<n; i++){
            if( start[i] != '_' ){
                idxs1.push_back(i);
                s1 += start[i];
            }
            if( target[i] != '_' ){
                idxs2.push_back(i);
                s2 += target[i];
            }
        }
        if( s1 != s2 ) return false;
        int size = s1.size();
        int last1 = 0, last2 = 0;
        for(int i=0; i<size; i++){
            int idx1 = idxs1[i], idx2 = idxs2[i];
            if( s1[i] == 'R' ){
                int space1 = idx1 - last1;
                int space2 = idx2 - last2;
                if( space1 > space2 ) return false;
            } else{
                int space1 = idx1 - last1;
                int space2 = idx2 - last2;
                if( space1 < space2 ) return false;
            }
        }
        return true;
    }
};