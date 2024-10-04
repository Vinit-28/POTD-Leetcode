// Problem Link : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/


// Solution //
using ll = long long;
class Solution {
private:
    bool isPossible(vector<int> &skill){
        int n = skill.size();
        int i = 0, j = n-1;
        int sumReq = skill[i] + skill[j];
        while( i < j ){
            if( skill[i++] + skill[j--] != sumReq ){
                return false;
            }
        }
        return true;
    }
public:
    long long dividePlayers(vector<int>& skill) {
        sort(begin(skill), end(skill));
        if( isPossible(skill) == false ) return -1;
        int n = skill.size();
        int i = 0, j = n-1;
        ll ans = 0;
        while( i<j ){
            ans += (skill[i++]*skill[j--]);
        }
        return ans;
    }
};