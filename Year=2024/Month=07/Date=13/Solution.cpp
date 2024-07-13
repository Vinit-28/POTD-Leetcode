// Problem Link : https://leetcode.com/problems/robot-collisions/description/


// Solution //
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        int n = pos.size();
        vector<vector<int>> arr;
        vector<int> finalHealth(n, -1), ans;
        for(int i=0; i<n; i++){
            arr.push_back({pos[i], i});
        }
        sort(begin(arr), end(arr));
        stack<vector<int>> st;
        for(auto &a : arr){
            int idx = a[1], h = health[idx];
            char d = dir[idx];
            if( d == 'L' ){
                while( !st.empty() && dir[st.top()[0]] == 'R' && st.top()[1] <= h ){
                    h -= (st.top()[1]==h? h : 1);
                    st.pop();
                }
                if( h > 0 && !st.empty() && dir[st.top()[0]] == 'R' ){
                    st.top()[1] -= 1;
                } else if( h > 0 ){
                    st.push({idx, h});
                }
            } else{
                st.push({idx, h});
            }
        }

        while( !st.empty() ){
            int idx = st.top()[0], h = st.top()[1];
            finalHealth[idx] = h;
            st.pop();
        }

        for(auto &h : finalHealth){
            if( h != -1 ){
                ans.push_back(h);
            }
        }
        return ans;
    }
};