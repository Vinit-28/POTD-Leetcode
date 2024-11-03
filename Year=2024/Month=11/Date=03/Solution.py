# Problem Link : https://leetcode.com/problems/rotate-string/description/


# Solution #
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n1 = len(s)
        n2 = len(goal)
        if n1 != n2:
            return False
        for idx in range(n1):
            if goal.endswith(s[:idx+1]) and goal.startswith(s[idx+1:]):
                return True
        return False