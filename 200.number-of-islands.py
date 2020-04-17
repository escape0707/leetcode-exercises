#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#
# https://leetcode.com/problems/number-of-islands/description/
#
# algorithms
# Medium (45.22%)
# Likes:    4595
# Dislikes: 171
# Total Accepted:    604.4K
# Total Submissions: 1.3M
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# Given a 2d grid map of '1's (land) and '0's (water), count the number of
# islands. An island is surrounded by water and is formed by connecting
# adjacent lands horizontally or vertically. You may assume all four edges of
# the grid are all surrounded by water.
#
# Example 1:
#
#
# Input:
# 11110
# 11010
# 11000
# 00000
#
# Output: 1
#
#
# Example 2:
#
#
# Input:
# 11000
# 11000
# 00100
# 00011
#
# Output: 3
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
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(i: int, j: int) -> None:
            if not (0 <= i < len(grid) and 0 <= j < len(grid[i]) and grid[i][j] == "1"):
                return
            grid[i][j] = "0"
            for di, dj in (-1, 0), (0, +1), (+1, 0), (0, -1):
                dfs(i + di, j + dj)

        ret = 0
        for i, row in enumerate(grid):
            for j, g in enumerate(row):
                if g == "1":
                    ret += 1
                    dfs(i, j)
        return ret


# @lc code=end
