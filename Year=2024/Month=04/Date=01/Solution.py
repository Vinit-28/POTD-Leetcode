# Problem Link : https://leetcode.com/problems/length-of-last-word/description/


# Solution #
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.strip().split(' ')[-1])