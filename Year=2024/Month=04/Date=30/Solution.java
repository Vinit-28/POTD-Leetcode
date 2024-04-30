// Problem Link : https://leetcode.com/problems/number-of-wonderful-substrings/description/


// Solution //
class Solution {
    public long wonderfulSubstrings(String word) {
        HashMap<Integer, Long> freqMap = new HashMap<Integer, Long>();
        int value = 0, mask;
        long count = 0;
        freqMap.put(0, (long)1);
        for(int idx=0; idx<word.length(); idx++){
            mask = 1<<((int)(word.charAt(idx)-'a'));
            value ^= mask;
            count += freqMap.getOrDefault(value, (long)0); // Finding the number of substrings ending at current index having all even frequencies //
            for(char ch='a'; ch<='j'; ch++){
                mask = 1<<((int)(ch-'a'));
                int oldValue = value ^ mask;
                count += freqMap.getOrDefault(oldValue, (long)0); // Finding the number of substrings ending at index having all the even frequencies except for the character ch //
            }
            freqMap.put(value, freqMap.getOrDefault(value, (long)0)+1);
        }
        return count;
    }
}
