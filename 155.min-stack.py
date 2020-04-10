#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#
# https://leetcode.com/problems/min-stack/description/
#
# algorithms
# Easy (41.87%)
# Likes:    2830
# Dislikes: 283
# Total Accepted:    447.8K
# Total Submissions: 1.1M
# Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' + '[[],[-2],[0],[-3],[],[],[],[]]'
#
# Design a stack that supports push, pop, top, and retrieving the minimum
# element in constant time.
#
#
# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.
#
#
#
#
# Example:
#
#
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> Returns -3.
# minStack.pop();
# minStack.top();      --> Returns 0.
# minStack.getMin();   --> Returns -2.
#
#
#
#
#

from collections import *
from functools import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minStack = []
        self.stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if len(self.minStack) == 0 or x <= self.minStack[-1]:
            self.minStack.append(x)

    def pop(self) -> None:
        if self.stack.pop() == self.minStack[-1]:
            self.minStack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end
