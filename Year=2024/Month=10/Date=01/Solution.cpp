// Problem Link : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/


// Solution //
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int mpp[k]; memset(mpp, 0, sizeof(mpp));
        for(auto &num : arr){
            int mod = ((num%k)+k)%k;
            mpp[mod] += 1;
        }
        for(int i=1; i<k; i++){
            if( mpp[i] != mpp[k-i] ) return false;
        }
        return mpp[0]&1? false : true;
    }
};