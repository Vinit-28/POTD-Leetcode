// Problem Link : https://leetcode.com/problems/frog-jump/


// Solution //
class Solution {
public:
    map<string, bool> dp;

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        dp.clear();
        return helper(stones, n, 0, 0);
    }

    bool helper(vector<int>& stones, int &n, int idx, long k){
        if( k < 0 ){
            return false;
        } else if( idx == stones.size()-1 ){
            return true;
        } else if( idx != -1 ){
            string key = to_string(idx) + "_" + to_string(k);
            if( dp.find(key) == dp.end() ){
                int nextIdx;
                bool ans = false;
                // Using k-1 units //
                nextIdx = getNextIdx(stones, n, idx, stones[idx]+k-1);
                ans = ans || helper(stones, n, nextIdx, k-1);
                // Using k units //
                nextIdx = getNextIdx(stones, n, idx, stones[idx]+k);
                ans = ans || helper(stones, n, nextIdx, k);
                // Using k+1 units //
                nextIdx = getNextIdx(stones, n, idx, stones[idx]+k+1);
                ans = ans || helper(stones, n, nextIdx, k+1);
                // storing the answer //
                dp[key] = ans;
            }
            return dp[key];
        }
        return false;
    }

    int getNextIdx(vector<int> &stones, int &n, int i, long value){
        int l=i+1, u=n-1, m=(l+u)/2;
        while(l<=u){
            if( value == stones[m] ){
                return m;
            } else if( stones[m] < value ){
                l = m+1;
            } else{
                u = m-1;
            }
            m = (l+u)/2;
        }
        return -1;
    }
};