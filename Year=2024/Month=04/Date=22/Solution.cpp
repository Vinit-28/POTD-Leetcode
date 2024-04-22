// Problem Link : https://leetcode.com/problems/open-the-lock/description/


// Solution //
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> _deadends(deadends.begin(), deadends.end()), visited;
        queue<string> q;
        int turns = 0;

        q.push("0000");
        visited.insert("0000");
        while( q.empty() == false ){
            int size = q.size();
            while( size-- > 0 ){
                auto lock = q.front(); q.pop();
                if( target == lock ) return turns;
                if( _deadends.find(lock) != _deadends.end() ) continue;
                for(char &wh : lock){
                    char bkp = wh;
                    for(int rotateBy : {1, -1}){
                        wh = rotate(bkp, rotateBy);
                        if( visited.find(lock) == visited.end() ){
                            q.push(lock);
                            visited.insert(lock);
                        }
                    }
                    wh = bkp;
                }
            }
            turns += 1;
        }
        return -1;
    }

    char rotate(char wh, int rotateBy){
        int wheel = wh-'0';
        if( (wheel + rotateBy) < 0 ) return '9';
        if( (wheel + rotateBy) > 9 ) return '0';
        return '0' + (wheel + rotateBy);
    }
};
