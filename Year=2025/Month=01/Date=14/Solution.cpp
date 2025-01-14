// Problem Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/


// Solution //
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        vector<int> C;
        int n = A.size();
        int bound = n+1;
        for(int idx=0; idx<n; idx++){
            int elea = A[idx]%bound;
            int eleb = B[idx]%bound;
            A[elea-1] += bound;
            B[eleb-1] += bound;
            count += A[eleb-1]>=bound;
            count += (elea != eleb? B[elea-1]>=bound : 0);
            C.push_back(count);
        }
        return C;
    }
};