// Problem Link : https://leetcode.com/problems/letter-tile-possibilities/description/


// Solution //
class Solution {
    private:
        int count;
    public:
        int numTilePossibilities(string tiles) {
            count = 0;
            int hmap[26] = {0};
            for(auto &ch: tiles){
                hmap[ch-'A'] += 1;
            }
            helper(hmap);
            return count-1; // -1 for empty. //
        }
    private:
        void helper(int hmap[]){
            count += 1;
            for(char ch='A'; ch<='Z'; ch++){
                if( hmap[ch-'A'] > 0 ){
                    hmap[ch-'A'] -= 1;
                    helper(hmap);
                    hmap[ch-'A'] += 1;
                }
            }
        }
    };