// Problem Link : https://leetcode.com/problems/spiral-matrix-iii/description/


// Solution //
class Solution {
private:
    bool isValid(int r, int c, int i, int j){
        return !(i<0 || j<0 || i>=r || j>= c);
    }

public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rs, int cs) {
        vector<vector<int>> ans;
        ans.push_back({rs, cs});
        if( cs+1 < c ) ans.push_back({rs, cs+1});
        if( cs+1 < c && rs+1 < r ) ans.push_back({rs+1, cs+1});
        if( rs+1 < r ) ans.push_back({rs+1, cs});
        int incre = 3;
        int it = 1;
        int total = r*c;
        while( ans.size() < total ){
            int temp;
            int i = rs+it, j = cs-it;
            temp = i;
            // Going Up //
            while( i > (temp-incre) ){
                if( isValid(r, c, i, j) ) ans.push_back({i, j});
                i -= 1;
            }
            i = rs-it, j = cs-it+1;
            temp = j;
            // Going Right //
            while( j < (temp+incre) ){
                if( isValid(r, c, i, j) ) ans.push_back({i, j});
                j += 1;
            }
            i = rs-it+1, j = cs+it+1;
            temp = i;
            // Going Down //
            while( i < (temp+incre) ){
                if( isValid(r, c, i, j) ) ans.push_back({i, j});
                i += 1;
            }
            i = rs+it+1, j = cs+it;
            temp = j;
            // Going Left //
            while( j > (temp-incre) ){
                if( isValid(r, c, i, j) ) ans.push_back({i, j});
                j -= 1;
            }
            it += 1;
            incre += 2;
        }
        return ans;
    }
};
