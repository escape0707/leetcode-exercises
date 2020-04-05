#
# @lc app=leetcode id=202 lang=python3
#
# [202] Happy Number
#
# https://leetcode.com/problems/happy-number/description/
#
# algorithms
# Easy (48.83%)
# Likes:    1728
# Dislikes: 374
# Total Accepted:    407.1K
# Total Submissions: 815.1K
# Testcase Example:  '19'
#
# Write an algorithm to determine if a number is "happy".
#
# A happy number is a number defined by the following process: Starting with
# any positive integer, replace the number by the sum of the squares of its
# digits, and repeat the process until the number equals 1 (where it will
# stay), or it loops endlessly in a cycle which does not include 1. Those
# numbers for which this process ends in 1 are happy numbers.
#
# Example:
#
#
# Input: 19
# Output: true
# Explanation:
# 1^2 + 9^2 = 82
# 8^2 + 2^2 = 68
# 6^2 + 8^2 = 100
# 1^2 + 0^2 + 0^2 = 1
#
#

from collections import *
from functools import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        def reversed_digits_of(i):
            while i:
                yield i % 10
                i /= 10

        def next_of(i):
            return sum(map(partial(pow, exp=2), reversed_digits_of(i)))

        slow = fast = n
        while True:
            slow = next_of(slow)
            fast = next_of(next_of(fast))
            if slow == fast:
                return slow == 1


# @lc code=end
