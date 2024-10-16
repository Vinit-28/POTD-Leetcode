// Problem Link : https://leetcode.com/problems/longest-happy-string/description/


// Solution //
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        char lastCh = '~';
        int freq = 0;
        string ans = "";
        priority_queue<pair<int,char>> pq;
        if( a > 0 ) pq.push({a, 'a'});
        if( b > 0 ) pq.push({b, 'b'});
        if( c > 0 ) pq.push({c, 'c'});

        while( pq.empty()==false ){
            auto top = pq.top(); pq.pop();
            auto [rem, newCh] = top;
            if( lastCh == newCh ) freq += 1;
            else lastCh = newCh, freq = 1; 
            if( freq == 3 ){
                if( pq.empty() ) break;
                else{
                    auto top2 = pq.top(); pq.pop(); pq.push(top);
                    auto [rem, newCh] = top2;
                    ans += newCh;
                    if( --rem > 0 ) pq.push({rem, newCh});
                    lastCh = newCh;
                    freq = 1;
                }
            } else{
                ans += newCh;
                if( --rem > 0 ) pq.push({rem, newCh});
            }
        }
        return ans;
    }
};