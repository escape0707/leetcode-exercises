#
# @lc app=leetcode id=64 lang=python3
#
# [64] Minimum Path Sum
#
# https://leetcode.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (51.46%)
# Likes:    2597
# Dislikes: 54
# Total Accepted:    384.8K
# Total Submissions: 725.1K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# Given a m x n grid filled with non-negative numbers, find a path from top
# left to bottom right which minimizes the sum of all numbers along its path.
#
# Note: You can only move either down or right at any point in time.
#
# Example:
#
#
# Input:
# [
# [1,3,1],
# ⁠ [1,5,1],
# ⁠ [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.
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
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not (grid and grid[0]):
            return 0

        grid[0] = list(accumulate(grid[0]))
        for i, row in islice(enumerate(grid), 1, None):
            row[0] += grid[i - 1][0]
            for j, num in islice(enumerate(row), 1, None):
                row[j] += min(row[j - 1], grid[i - 1][j])
        return grid[-1][-1]


# @lc code=end
