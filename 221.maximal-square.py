#
# @lc app=leetcode id=221 lang=python3
#
# [221] Maximal Square
#
# https://leetcode.com/problems/maximal-square/description/
#
# algorithms
# Medium (35.65%)
# Likes:    2439
# Dislikes: 63
# Total Accepted:    207.3K
# Total Submissions: 575.5K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# Given a 2D binary matrix filled with 0's and 1's, find the largest square
# containing only 1's and return its area.
#
# Example:
#
#
# Input:
#
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
#
# Output: 4
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
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not (matrix and matrix[0]):
            return 0
        top = list(map(int, matrix[0]))
        # The edge length of the maximal all '1' square
        # which its bottom-right corner is matrix[i][j].
        dp = top[:]
        max_edge_length = max(dp)
        for row in islice(matrix, 1, None):
            first = int(row[0])
            left = first
            prev = dp[0]
            dp[0] = first
            max_edge_length = max(max_edge_length, dp[0])
            for j, c in islice(enumerate(row), 1, None):
                num = int(c)
                cache = dp[j]
                dp[j] = num and min(prev, left, top[j]) + 1
                max_edge_length = max(max_edge_length, dp[j])
                prev = cache
                left = num and left + 1
                top[j] = num and top[j] + 1
        return max_edge_length * max_edge_length


# @lc code=end
