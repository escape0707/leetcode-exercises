# @lc app=leetcode id=1351 lang=python3

from collections import *
from functools import *
from itertools import *
from operator import *
from typing import *


# @lc code=start
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        N = len(grid[0])
        i = N - 1
        for row in grid:
            while i >= 0 and row[i] < 0:
                i -= 1
            count += N - i - 1
        return count


# @lc code=end
