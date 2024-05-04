// Problem Link : https://leetcode.com/problems/boats-to-save-people/description/


// Solution //
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1;
        int boats = 0;
        while( left < right ){
            if( (people[left]+people[right]) > limit ){
                right -= 1;
            } else{
                left += 1, right -= 1;
            }
            boats += 1; 
        }
        return left==right? boats+1 : boats;
    }
};