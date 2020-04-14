#
# @lc app=leetcode id=525 lang=python3
#
# [525] Contiguous Array
#
# https://leetcode.com/problems/contiguous-array/description/
#
# algorithms
# Medium (44.75%)
# Likes:    1283
# Dislikes: 63
# Total Accepted:    70.4K
# Total Submissions: 165.9K
# Testcase Example:  '[0,1]'
#
# Given a binary array, find the maximum length of a contiguous subarray with
# equal number of 0 and 1.
#
#
# Example 1:
#
# Input: [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with equal number of 0
# and 1.
#
#
#
# Example 2:
#
# Input: [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
# number of 0 and 1.
#
#
#
# Note:
# The length of the given binary array will not exceed 50,000.
#
#

from collections import *
from functools import *
from heapq import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        s = ret = 0
        hashmap = [-1] + [None] * len(nums) * 2
        for i, num in enumerate(nums):
            s += (num << 1) - 1
            if hashmap[s] is None:
                hashmap[s] = i
            else:
                ret = max(ret, i - hashmap[s])
        return ret


# @lc code=end
