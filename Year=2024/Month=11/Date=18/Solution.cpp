// Problem Link : https://leetcode.com/problems/defuse-the-bomb/description/


// Solution //
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if( k > 0 ){
            int idx = n-1;
            int sum = 0;
            for(int i=n-1; i>=n-k; i--) sum += code[i];
            for(int i=n-k-1; i>=0; i--){
                ans[i] = sum;
                sum -= code[idx];
                sum += code[i];
                idx -= 1;
            }
            for(int i=n-1; i>=n-k; i--){
                ans[i] = sum;
                sum -= code[idx];
                sum += code[i];
                idx -= 1;
            }
        } else if( k < 0 ){
            k = abs(k);
            int idx = 0;
            int sum = 0;
            for(int i=0; i<k; i++) sum += code[i];
            for(int i=k; i<n; i++){
                ans[i] = sum;
                sum -= code[idx];
                sum += code[i];
                idx += 1;
            }
            for(int i=0; i<k; i++){
                ans[i] = sum;
                sum -= code[idx];
                sum += code[i];
                idx += 1;
            }
        }
        return ans;
    }
};