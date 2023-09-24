// Problem Link : https://leetcode.com/problems/longest-string-chain/description/


// Solution //
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(2);
        bool doContinue = true;
        int idx = 0;
        glasses[0] = {double(poured)};

        while( doContinue && idx <= 100 ){
            doContinue = false;
            glasses[1] = vector<double>(idx+2, 0.0);
            for(int i=0;i<glasses[0].size();i++){
                if( glasses[0][i] > 1.0 ){
                    double extra =  glasses[0][i] - 1.0;
                    double half = extra/2.0;
                    glasses[1][i] += half;
                    glasses[1][i+1] += half;
                    glasses[0][i] = 1.0;
                    doContinue = true;
                }
            }
            if( query_row == idx ){
                return glasses[0][query_glass];
            }
            glasses[0] = glasses[1];
            idx += 1;
        }
        return 0.0;
    }
};