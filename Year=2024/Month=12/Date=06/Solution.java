// Problem Link : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/


// Solution //
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> set = new HashSet<Integer>();
        for(int ele : banned){
            set.add(ele);
        }
        int count = 0;
        for(int ele=1; ele<=n; ele++){
            if( set.contains(ele) ){
                continue;
            } 
            if( maxSum >= ele ){
                maxSum -= ele;
                count += 1;
            } else{
                break;
            }
        }
        return count;
    }
}