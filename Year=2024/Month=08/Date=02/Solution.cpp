// Problem Link : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/


// Solution //
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int prefixOnes[n];
        int minOps = n;
        // Finding the prefix sum //
        prefixOnes[0] = nums[0]==1;
        for(int i=1; i<n; i++){
            prefixOnes[i] = prefixOnes[i-1] + nums[i];
        }
        // Trying all the possibilities of Left-Right //
        int totalOnes = prefixOnes[n-1];
        if( totalOnes == 0 || totalOnes == n ) return 0;
        for(int leftReq=0; leftReq<=totalOnes; leftReq++){
            int rightReq = totalOnes-leftReq;
            int leftAvailable = leftReq>0? prefixOnes[leftReq-1] : 0;
            int rightAvailable = rightReq>0? prefixOnes[n-1]-prefixOnes[n-rightReq-1] : 0;
            int ops = (leftReq - leftAvailable) + (rightReq - rightAvailable);
            minOps = min(minOps, ops);
        }
        // Consider all the zeros somewhere in the middle //
        for(int i=0; i<=(n-totalOnes); i++){
            int available = (i==0? prefixOnes[totalOnes-1] : prefixOnes[i+totalOnes-1]-prefixOnes[i-1]);
            int ops = totalOnes - available;
            minOps = min(minOps, ops);
        }
        return minOps;
    }
};