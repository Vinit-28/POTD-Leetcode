// Problem Link : https://leetcode.com/problems/compare-version-numbers/description/


// Solution //
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1 = 0, idx2 = 0;
        int n1 = version1.length(), n2 = version2.length();
        while( idx1 < n1 || idx2 < n2 ){
            int r1 = getRevision(version1, idx1);
            int r2 = getRevision(version2, idx2);
            if( r1 < r2 ) return -1;
            else if( r1 > r2 ) return 1;
        }
        return 0;
    }

    int getRevision(string version, int &idx){
        if( idx >= version.length() ) return 0;
        string revStr = "";
        int n = version.length();
        while( idx < n && version[idx] != '.' ){
            revStr += version[idx];
            idx += 1;
        }
        idx += 1; // moving from '.' to next character //
        return stoi(revStr);
    }
};
