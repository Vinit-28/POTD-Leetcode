// Problem Link : https://leetcode.com/problems/most-beautiful-item-for-each-query/description/


// Solution //
class Solution {
private:
    int getIdx(vector<vector<int>> &items, int maxPrice){
        int idx = -1;
        int l = 0, u = items.size()-1;
        while( l<=u ){
            int mid = (l+u)/2;
            if( items[mid][0] <= maxPrice ){
                idx = mid;
                l = mid+1;
            } else{
                u = mid-1;
            }
        }
        return idx;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items), end(items), [](vector<int> &item1, vector<int> &item2)->bool{
           return item1[0] < item2[0]; 
        });
        int n = items.size();
        vector<int> prefixMax(n);
        vector<int> ans;
        prefixMax[0] = items[0][1];
        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], items[i][1]);
        }
        
        for(auto &q : queries){
            int idx = getIdx(items, q);
            if( idx == -1 ) ans.push_back(0);
            else ans.push_back(prefixMax[idx]);
        }
        return ans;
    }
};