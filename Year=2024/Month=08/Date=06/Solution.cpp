// Problem Link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/


// Solution //
class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<int> pq;
        int hmap[26] = {0};
        for(auto &ch : word) hmap[ch-'a'] += 1;
        for(int i=0; i<26; i++) pq.push(hmap[i]);
        int key = 2, round = 1;
        int ans = 0;
        while( pq.empty()==false ){
            int l = pq.top(); pq.pop();
            ans += (round * l);
            key += 1;
            if( key == 10 ) key = 2, round += 1;
        }
        return ans;
    }
};
