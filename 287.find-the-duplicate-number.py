#
# @lc app=leetcode id=287 lang=python3
#
# [287] Find the Duplicate Number
#
# https://leetcode.com/problems/find-the-duplicate-number/description/
#
# algorithms
# Medium (52.48%)
# Likes:    3731
# Dislikes: 464
# Total Accepted:    278K
# Total Submissions: 524.5K
# Testcase Example:  '[1,3,4,2,2]'
#
# Given an array nums containing n + 1 integers where each integer is between 1
# and n (inclusive), prove that at least one duplicate number must exist.
# Assume that there is only one duplicate number, find the duplicate one.
#
# Example 1:
#
#
# Input: [1,3,4,2,2]
# Output: 2
#
#
# Example 2:
#
#
# Input: [3,1,3,4,2]
# Output: 3
#
# Note:
#
#
# You must not modify the array (assume the array is read only).
# You must use only constant, O(1) extra space.
# Your runtime complexity should be less than O(n^2).
# There is only one duplicate number in the array, but it could be repeated
# more than once.
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
    def findDuplicate(self, nums: List[int]) -> int:
        def floyd(start):
            slow = fast = start
            while True:
                slow = nums[slow]
                fast = nums[nums[fast]]
                if slow == fast:
                    return slow

        for i in range(len(nums)):
            # In this problem, num belongs to [1, len(nums) - 1]
            # So we'll definitely go through the duplicate number from nums[0]
            # which means the following condition will always be true
            # and the for-loop body will only execute once
            if (meet := floyd(i)) != i:
                while meet != i:
                    meet = nums[meet]
                    i = nums[i]
                return meet
        raise ValueError(nums)


# @lc code=end
