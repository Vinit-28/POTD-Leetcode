// Problem Link : https://leetcode.com/problems/maximum-swap/description/


// Solution //
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();
        for(int i=0; i<n; i++){
            int maxIdx = i;
            for(int j=i+1; j<n; j++){
                if( str[j] >= str[maxIdx] ){
                    maxIdx = j;
                }
            }
            if( str[i] != str[maxIdx] ){
                swap(str[i], str[maxIdx]);
                return stoi(str);
            }
        }
        return num;
    }
};