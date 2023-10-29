// Problem Link : https://leetcode.com/problems/poor-pigs/description/


// Solution //
class Solution {
public:
    int poorPigs(int buckets, int mtd, int mtt) {
        int rounds = mtt / mtd;
        for(int i=0;i<=buckets;i++){
            if( pow(rounds+1, i) >= buckets ){
                return i;
            }
        }
        return -1;
    }
};