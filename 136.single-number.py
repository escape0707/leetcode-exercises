#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#
# https://leetcode.com/problems/single-number/description/
#
# algorithms
# Easy (62.81%)
# Likes:    3685
# Dislikes: 144
# Total Accepted:    671.7K
# Total Submissions: 1.1M
# Testcase Example:  '[2,2,1]'
#
# Given a non-empty array of integers, every element appears twice except for
# one. Find that single one.
#
# Note:
#
# Your algorithm should have a linear runtime complexity. Could you implement
# it without using extra memory?
#
# Example 1:
#
#
# Input: [2,2,1]
# Output: 1
#
#
# Example 2:
#
#
# Input: [4,1,2,1,2]
# Output: 4
#
#
#

from collections import *
from functools import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums)


# @lc code=end
