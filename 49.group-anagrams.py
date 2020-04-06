#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#
# https://leetcode.com/problems/group-anagrams/description/
#
# algorithms
# Medium (52.44%)
# Likes:    2767
# Dislikes: 157
# Total Accepted:    525.5K
# Total Submissions: 979.7K
# Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
#
# Given an array of strings, group anagrams together.
#
# Example:
#
#
# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
# ⁠ ["ate","eat","tea"],
# ⁠ ["nat","tan"],
# ⁠ ["bat"]
# ]
#
# Note:
#
#
# All inputs will be in lowercase.
# The order of your output does not matter.
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
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def sorted_str(s: str) -> str:
            counts = [0] * 26
            for c in s:
                counts[ord(c) - 97] += 1
            return "".join(
                chain.from_iterable(
                    repeat(chr(97 + i), count) for i, count in enumerate(counts)
                )
            )

        groups: DefaultDict[str, List[str]] = defaultdict(list)
        for s in strs:
            groups[sorted_str(s)].append(s)
        return list(groups.values())


# @lc code=end
