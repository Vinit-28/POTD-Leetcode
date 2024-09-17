# Problem Link : https://leetcode.com/problems/minimum-time-difference/description/


# Solution #
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words = s1.split(' ') + s2.split(' ')
        mpp = dict()
        for word in words:
            mpp[word] = mpp.get(word, 0) + 1
        return [word for word, count in mpp.items() if count==1]

        