// Problem Link : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/


// Solution //
class Solution {
public:
    vector<int> ans;
    vector<int> constructDistancedSequence(int n) {
        vector<int> arr(n*2-1,-1);
        vector<bool> mpp(n+1,false);
        helper(n, arr, 0, mpp);
        return ans;
    }
private:
    bool helper(int &n, vector<int> &arr, int idx, vector<bool> &mpp){
        if( idx == arr.size() ){
            ans = arr;
            return true;
        } else if( arr[idx]==-1 ){
            for(int num=n; num>0; num--){
                if( mpp[num]==false && (num==1 || (idx+num < arr.size() && arr[idx+num]==-1)) ){
                    arr[idx] = num;
                    if( num > 1 ) arr[idx+num] = num;
                    mpp[num] = true;
                    if( helper(n, arr, idx+1, mpp) ) return true;
                    arr[idx] = -1;
                    if( num > 1 ) arr[idx+num] = -1;
                    mpp[num] = false;
                }
            }
        } else{
            return helper(n, arr, idx+1, mpp);
        }
        return false;
    }
};