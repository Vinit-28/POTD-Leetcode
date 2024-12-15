// Problem Link : https://leetcode.com/problems/maximum-average-pass-ratio/description/


// Solution //
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        
        for(int i=0; i<n; i++){
            double curr = classes[i][0]*1.0/classes[i][1];
            double next = (classes[i][0]+1)*1.0/(classes[i][1]+1);
            pq.push({next-curr, i});
        }
        while( k-- > 0 ){
            auto [v, idx] = pq.top(); pq.pop();
            classes[idx][0] += 1;
            classes[idx][1] += 1;
            double curr = classes[idx][0]*1.0/classes[idx][1];
            double next = (classes[idx][0]+1)*1.0/(classes[idx][1]+1);
            pq.push({next-curr, idx});
        }
        double sum = 0.0;
        for(int i=0; i<n; i++){
            double val = classes[i][0]*1.0/classes[i][1];
            sum += val;
        }
        return sum/n;
    }
};