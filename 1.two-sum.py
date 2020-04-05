#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum/description/
#
# algorithms
# Easy (45.07%)
# Likes:    13483
# Dislikes: 493
# Total Accepted:    2.6M
# Total Submissions: 5.7M
# Testcase Example:  '[2,7,11,15]\n9'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
#
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
#
# Example:
#
#
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
#
#
#

from collections import *
from functools import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
# class Solution:
#     def twoSum(self, nums, target: int) -> List[int]:
#         nums = list(zip(nums, count()))
#         nums.sort()
#         left, right = 0, len(nums) - 1
#         while left < right:
#             s = nums[left][0] + nums[right][0]
#             if s == target:
#                 return [nums[left][1], nums[right][1]]
#             if s < target:
#                 left += 1
#             else:
#                 right -= 1
#         raise ValueError(nums)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        occurred: Dict[int, int] = dict()
        for i, num in enumerate(nums):
            if (j := occurred.get(target - num)) is not None:
                return [j, i]
            occurred[num] = i
        raise ValueError(nums)


# @lc code=end
