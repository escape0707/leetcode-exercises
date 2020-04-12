#
# @lc app=leetcode id=1046 lang=python3
#
# [1046] Last Stone Weight
#
# https://leetcode.com/problems/last-stone-weight/description/
#
# algorithms
# Easy (62.59%)
# Likes:    444
# Dislikes: 23
# Total Accepted:    46.9K
# Total Submissions: 74.6K
# Testcase Example:  '[2,7,4,1,8,1]'
#
# We have a collection of stones, each stone has a positive integer weight.
#
# Each turn, we choose the two heaviest stones and smash them together.
# Suppose the stones have weights x and y with x <= y.  The result of this
# smash is:
#
#
# If x == y, both stones are totally destroyed;
# If x != y, the stone of weight x is totally destroyed, and the stone of
# weight y has new weight y-x.
#
#
# At the end, there is at most 1 stone left.  Return the weight of this stone
# (or 0 if there are no stones left.)
#
#
#
# Example 1:
#
#
# Input: [2,7,4,1,8,1]
# Output: 1
# Explanation:
# We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
# we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
# we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
# we combine 1 and 1 to get 0 so the array converts to [1] then that's the
# value of last stone.
#
#
#
# Note:
#
#
# 1 <= stones.length <= 30
# 1 <= stones[i] <= 1000
#
#
#

from collections import *
from functools import *
from heapq import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
# Don't use these methods! They are private and might change after times!
# Negate ints in stones and use a min heap instead!
from heapq import _heapify_max, _heappop_max, _heapreplace_max

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        _heapify_max(stones)
        while len(stones) > 1:
            x = _heappop_max(stones)
            y = stones[0]
            if x == y:
                _heappop_max(stones)
            else:
                _heapreplace_max(stones, x - y)
        return stones[0] if stones else 0
# @lc code=end
