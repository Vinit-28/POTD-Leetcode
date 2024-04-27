// Problem Link : https://leetcode.com/problems/freedom-trail/description/


// Solution //
class Solution {
public:
    int dp[101][101];
    int findRotateSteps(string ring, string key) {
        vector<int> indices[26];
        int ringSize = ring.size();
        memset(dp, -1, sizeof(dp));
        for(int idx=0; idx<ringSize; idx++){
            indices[ring[idx]-'a'].push_back(idx);
        }
        return DFS(ring, key, 0, 0, indices);
    }

    int DFS(string &ring, string &key, int kIdx, int rIdx, vector<int> indices[]){
        if( kIdx == key.size() ){
            return 0;
        } else if( dp[kIdx][rIdx] == -1 ){
            int minSteps = INT_MAX;
            char lookingFor = key[kIdx];
            for(auto &idx : indices[lookingFor-'a']){
                int steps;
                if( rIdx < idx ){
                    steps = min(int(idx-rIdx), int(rIdx+(ring.size()-idx))); // min(clockWise, antiClockWise) //
                } else{
                    steps = min(int((ring.size()-rIdx)+idx), int(rIdx-idx)); // min(clockWise, antiClockWise) //
                }
                int totalSteps = steps + DFS(ring, key, kIdx+1, idx, indices);
                minSteps = min(minSteps, totalSteps);
            }
            dp[kIdx][rIdx] = minSteps + 1;
        }
        return dp[kIdx][rIdx];
    }
};
