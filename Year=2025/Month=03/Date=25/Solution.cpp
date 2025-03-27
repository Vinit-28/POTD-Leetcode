// Problem Link : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/


// Solution //
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int vcount = verticalComponents(rectangles);
        int hcount = horizontalComponents(rectangles);
        return vcount > 2 || hcount > 2;
    }
    
    int verticalComponents(vector<vector<int>> &rect){
        int count = 0;
        int n = rect.size();
        vector<pair<int,int>> arr;
        for(auto &r : rect){
            arr.push_back({r[1], r[3]});
        }
        sort(begin(arr), end(arr));
        int start = -1, end = -1;
        for(auto &[s, e]: arr){
            if( s >= start && s < end ){
                end = max(end, e);
            } else {
                count += 1;
                start = s, end = e;
            }
        }
        return count;
    }
    
    int horizontalComponents(vector<vector<int>> &rect){
        int count = 0;
        int n = rect.size();
        vector<pair<int,int>> arr;
        for(auto &r : rect){
            arr.push_back({r[0], r[2]});
        }
        sort(begin(arr), end(arr));
        int start = -1, end = -1;
        for(auto &[s, e]: arr){
            if( s >= start && s < end ){
                end = max(end, e);
            } else {
                count += 1;
                start = s, end = e;
            }
        }
        return count;
    }
};