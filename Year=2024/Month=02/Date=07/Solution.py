# Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/description/


# Solution #
class Solution:
    def frequencySort(self, s: str) -> str:
        freq = dict()
        ans = ""
        for ch in s:
            freq[ch] = freq[ch]+1 if ch in freq else 1
        freq = dict(sorted(freq.items(), key=lambda item: item[1], reverse=True))
        for ch,count in freq.items():
            ans += ch*count
        return ans
