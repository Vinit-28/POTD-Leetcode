// Problem Link : https://leetcode.com/problems/walking-robot-simulation/description/


// Solution //
class Solution {
private:
    map<char,pair<int,int>> steps;
    map<pair<char,int>,char> changeDir;
public:
    Solution(){
        // Steps as per the direction //
        steps['N'] = {0,1};
        steps['E'] = {1,0};
        steps['S'] = {0,-1};
        steps['W'] = {-1,0};
        // Change the direction as per the input //
        changeDir[{'N',-1}] = 'E';
        changeDir[{'N',-2}] = 'W';
        changeDir[{'E',-1}] = 'S';
        changeDir[{'E',-2}] = 'N';
        changeDir[{'S',-1}] = 'W';
        changeDir[{'S',-2}] = 'E';
        changeDir[{'W',-1}] = 'N';
        changeDir[{'W',-2}] = 'S';
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> obs(begin(obstacles), end(obstacles));
        int x = 0, y = 0;
        char currDir = 'N';
        int maxDist = 0;
        for(auto &com : commands){
            if( com > 0 ){ // Move //
                while( com > 0 ){
                    x += steps[currDir].first;
                    y += steps[currDir].second;
                    if( obs.count({x, y}) ){
                        x -= steps[currDir].first;
                        y -= steps[currDir].second;
                        break;
                    }
                    maxDist = max(maxDist, (x*x)+(y*y));
                    com -= 1;
                }
            } else{ // Change Direction //
                currDir = changeDir[{currDir, com}];
            }
        }
        return maxDist;
    }
};