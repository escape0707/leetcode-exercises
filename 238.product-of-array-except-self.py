#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#
# https://leetcode.com/problems/product-of-array-except-self/description/
#
# algorithms
# Medium (58.46%)
# Likes:    4063
# Dislikes: 347
# Total Accepted:    436.1K
# Total Submissions: 738K
# Testcase Example:  '[1,2,3,4]'
#
# Given an array nums of n integers where n > 1,  return an array output such
# that output[i] is equal to the product of all the elements of nums except
# nums[i].
#
# Example:
#
#
# Input:  [1,2,3,4]
# Output: [24,12,8,6]
#
#
# Constraint: It's guaranteed that the product of the elements of any prefix or
# suffix of the array (including the whole array) fits in a 32 bit integer.
#
# Note: Please solve it without division and in O(n).
#
# Follow up:
# Could you solve it with constant space complexity? (The output array does not
# count as extra space for the purpose of space complexity analysis.)
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
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ret = list(accumulate(islice(nums, len(nums) - 1), mul, initial=1))
        for i, pre in zip(
            count(-1, -1),
            accumulate(islice(reversed(nums), len(nums) - 1), mul, initial=1),
        ):
            ret[i] *= pre
        return ret


# @lc code=end
