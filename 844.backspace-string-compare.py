#
# @lc app=leetcode id=844 lang=python3
#
# [844] Backspace String Compare
#
# https://leetcode.com/problems/backspace-string-compare/description/
#
# algorithms
# Easy (47.22%)
# Likes:    1129
# Dislikes: 63
# Total Accepted:    113.4K
# Total Submissions: 239.1K
# Testcase Example:  '"ab#c"\n"ad#c"'
#
# Given two strings S and T, return if they are equal when both are typed into
# empty text editors. # means a backspace character.
#
#
# Example 1:
#
#
# Input: S = "ab#c", T = "ad#c"
# Output: true
# Explanation: Both S and T become "ac".
#
#
#
# Example 2:
#
#
# Input: S = "ab##", T = "c#d#"
# Output: true
# Explanation: Both S and T become "".
#
#
#
# Example 3:
#
#
# Input: S = "a##c", T = "#a#c"
# Output: true
# Explanation: Both S and T become "c".
#
#
#
# Example 4:
#
#
# Input: S = "a#c", T = "b"
# Output: false
# Explanation: S becomes "c" while T becomes "b".
#
#
# Note:
#
#
# 1 <= S.length <= 200
# 1 <= T.length <= 200
# S and T only contain lowercase letters and '#' characters.
#
#
# Follow up:
#
#
# Can you solve it in O(N) time and O(1) space?
#
#
#
#
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
    def backspaceCompare(self, S: str, T: str) -> bool:
        def backspaced(s):
            hashtags = 0
            for c in reversed(s):
                if c == "#":
                    hashtags += 1
                    continue
                if hashtags:
                    hashtags -= 1
                    continue
                yield c

        return all(starmap(eq, zip_longest(backspaced(S), backspaced(T))))


# @lc code=end
