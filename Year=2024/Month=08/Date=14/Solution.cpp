// Problem Link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/



// Solution //
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int ans = -1;
        int l = 0, u = nums[n-1] - nums[0];
        while( l<=u ){
            int mid = (l+u)/2;
            int pairs = numberOfPairs(nums, n, mid);
            if( pairs >= k ){
                ans = mid;
                u = mid-1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }

    int numberOfPairs(vector<int> &nums, int n, int maxDist){
        int pairs = 0;
        int right = 1;
        for(int left=0; left<=n; left++){
            right = max(left+1, right);
            while( right < n && (nums[right] - nums[left]) <= maxDist ){
                right += 1;
            }
            int count = right - left - 1;
            pairs += count;
        }
        return pairs;
    }
};