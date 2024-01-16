# Problem Link : https://leetcode.com/problems/insert-delete-getrandom-o1/description/


# Solution #
from random import choice
class RandomizedSet:
    def __init__(self):
        self.lst = []
        self.map = {}

    def insert(self, val: int) -> bool:
        if val in self.map:
            return False
        self.lst.append(val)
        self.map[val] = len(self.lst)-1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.map:
            return False
        '''
            To delete the given value in O(1) TC, we will swap the givenValue 
            with the lastIdxValue and then simply delete/pop the last value
            from the list.
        '''
        idx = self.map[val]
        self.map[self.lst[-1]] = idx
        self.lst[idx], self.lst[-1] = self.lst[-1], self.lst[idx]
        self.lst.pop()
        del self.map[val]
        return True


    def getRandom(self) -> int:
        return choice(self.lst)
