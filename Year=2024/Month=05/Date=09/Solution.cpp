// Problem Link :https://leetcode.com/problems/maximize-happiness-of-selected-children/description/


// Solution //
class Solution {
public:
    using ll = long long;
    ll maximumHappinessSum(vector<int>& happiness, int k) {
        ll sum = 0;
        ll deduction = 0;
        int idx = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        while( k-- > 0 ){
            sum += max(ll(0), ll(happiness[idx++] - deduction++));
        }
        return sum;
    }
};
