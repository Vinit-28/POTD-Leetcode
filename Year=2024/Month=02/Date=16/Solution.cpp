// Problem Link : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/


// Solution //
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        int elesDeleted = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> freqs;
        // Calculating the frequencies //
        for(auto &ele : arr){
            freqMap[ele] += 1;
        }
        // Storing the frequencies in a vector //
        for(auto &p : freqMap){
            freqs.push_back(p.second);
        }
        // Sorting the frequencies // 
        sort(freqs.begin(), freqs.end());
        // Removing the frequencies(lowest first) //
        for(int i=0;i<freqs.size();i++){
            if( k < freqs[i] ){
                break;
            }
            k -= freqs[i];
            elesDeleted += 1;
        }
        return freqs.size() - elesDeleted;
    }
};
