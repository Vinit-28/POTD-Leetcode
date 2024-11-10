// Problem Link : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/


// Solution //
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n][31];
        // Prefix Sum //         
        for(int i=0; i<n; i++){
            for(int bitIdx=0; bitIdx<31; bitIdx++){
                int bit = (nums[i]>>bitIdx)&1;
                prefix[i][bitIdx] = bit;
                if( i > 0 ) prefix[i][bitIdx] += prefix[i-1][bitIdx];
            }
        }
        // Sliding Window //
        int right = 0;
        int currOrVal = 0;
        int minWindowLen = INT_MAX;
        for(int left=0; left<n; left++){
            // Extending the window //             
            while( right < n && (currOrVal < k || right==left) ){
                currOrVal |= nums[right];
                right += 1;
            }
            // If we have found the valid window //
            if( currOrVal >= k ){
                int windowLen = (right - left);
                minWindowLen = min(minWindowLen, windowLen);
            }
            // Sliding the window //
            currOrVal = removeElementFromWindow(prefix, left, right-1);
        }
        return minWindowLen==INT_MAX? -1 : minWindowLen;
    }
    
    int removeElementFromWindow(int prefix[][31], int idxToRem, int currIdx){
        int newOrVal = 0;
        for(int bitIdx=0; bitIdx<31; bitIdx++){
            int bitSum = prefix[currIdx][bitIdx] - prefix[idxToRem][bitIdx];
            if( bitSum > 0 ) newOrVal += (1<<bitIdx);
        }
        return newOrVal;
    }
};