// Problem Link : https://leetcode.com/problems/132-pattern/description/


// Solution //
class Solution {
public:
    void findClosestPrevMax(vector<int> &nums, int prevMaxs[], int &n){
        stack<int> st;
        for(int i=0;i<n;i++){
            while( st.empty()==false && nums[st.top()] <= nums[i] ){
                st.pop();
            }
            if( st.empty() ){
                prevMaxs[i] = -1;
            } else{
                prevMaxs[i] = st.top();
            }
            st.push(i);
        }
    }

    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int prefixMini[n], prevMaxs[n];
        prefixMini[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixMini[i] = min(prefixMini[i-1], nums[i]);
        }
        findClosestPrevMax(nums, prevMaxs, n);
        for(int i=n-1;i>0;i--){
            if( prevMaxs[i] != -1 ){
                int idx = prevMaxs[i];
                if( nums[idx] > prefixMini[idx] && nums[i] > prefixMini[idx] ){
                    return true;
                }
            }
        }
        return false;
    }
};