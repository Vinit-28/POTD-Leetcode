# Problem Link : https://leetcode.com/problems/circular-sentence/description/


# Solution #
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split(' ')
        for idx in range(len(words)):
            if words[idx][0] != words[idx-1][-1]:
                return False
        return True