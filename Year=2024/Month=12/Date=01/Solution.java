// Problem Link : https://leetcode.com/problems/check-if-n-and-its-double-exist/description/


// Solution //
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> st = new TreeSet<>();
        for(int ele: arr){
            if( ((ele&1)==0 && st.contains(ele/2)) || st.contains(ele*2) ){
                return true;
            }
            st.add(ele);
        }
        return false;
    }
}