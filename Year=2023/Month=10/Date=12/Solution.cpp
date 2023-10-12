// Problem Link : https://leetcode.com/problems/find-in-mountain-array/description/


// Solution //
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIdx = getPeakIdx(mountainArr);
        cout<<peakIdx<<endl;
        int targetIdx = search(mountainArr, target, 0, peakIdx, false);
        if( targetIdx == -1 ){
            targetIdx = search(mountainArr, target, peakIdx+1, mountainArr.length()-1, true);
        }
        return targetIdx;
    }

    int getPeakIdx(MountainArray &mountainArr){
        int size = mountainArr.length();
        int l = 0, u = size-1, m = (l+u)/2;
        while( l<=u ){
            int prev = m==0? -1 : mountainArr.get(m-1);
            int curr = mountainArr.get(m);

            if( isPeakIdx(mountainArr, m, curr, prev) ){
                return m;
            } else if( m==0 || prev < curr ){
                l = m+1;
            } else{
                u = m-1;
            }
            m = (l+u)/2;
        }
        return -1;
    }

    bool isPeakIdx(MountainArray &mountainArr, int &idx, int &curr, int &prev){
        if( idx == 0 || idx == mountainArr.length()-1 ){
            return false;
        }
        return (prev < curr) && (mountainArr.get(idx+1) < curr);
    }

    int search(MountainArray &mountainArr, int target, int l, int u, bool isReversed){
        int m = (l+u)/2;
        while( l<=u ){
            int curr = mountainArr.get(m);
            if( curr == target ){
                return m;
            } else if( isReversed ){
                if( curr < target ){
                    u = m-1;
                } else{
                    l = m+1;
                }
            } else{
                if( curr > target ){
                    u = m-1;
                } else{
                    l = m+1;
                }
            }
            m = (l+u)/2;
        }
        return -1;
    }
};