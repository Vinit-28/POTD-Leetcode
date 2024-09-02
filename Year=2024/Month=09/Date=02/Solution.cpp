// Problem Link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/


// Solution //
class Solution {
public:
    using ll = long long;
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = accumulate(begin(chalk), end(chalk), ll(0));
        int n = chalk.size();
        k %= sum;
        for(int i=0; i<n; i++){
            if( k < chalk[i] ) return i;
            k -= chalk[i];
        }
        return -1;
    }
};