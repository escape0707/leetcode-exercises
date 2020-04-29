#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
# https://leetcode.com/problems/sort-an-array/description/
#
# algorithms
# Medium (62.74%)
# Likes:    343
# Dislikes: 226
# Total Accepted:    63.1K
# Total Submissions: 100.4K
# Testcase Example:  '[5,2,3,1]'
#
# Given an array of integers nums, sort the array in ascending order.
#
#
# Example 1:
# Input: nums = [5,2,3,1]
# Output: [1,2,3,5]
# Example 2:
# Input: nums = [5,1,1,2,0,0]
# Output: [0,0,1,1,2,5]
#
#
# Constraints:
#
#
# 1 <= nums.length <= 50000
# -50000 <= nums[i] <= 50000
#
#
#

from bisect import *
from collections import *
from functools import *
from heapq import *
from itertools import *
from math import *
from operator import *
from typing import *


# @lc code=start
# I won't try to implement such a fundamental algorithm in a language
# with such high level like Python.
# Python don't even have a real pointer and it will never be pythonic.
# Do it in C (like CPython) or C++ instead, please.
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        return nums


# @lc code=end
