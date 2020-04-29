#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
#
# https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#
# algorithms
# Hard (32.60%)
# Likes:    2915
# Dislikes: 243
# Total Accepted:    300K
# Total Submissions: 915.9K
# Testcase Example:  '[1,2,3]'
#
# Given a non-empty binary tree, find the maximum path sum.
#
# For this problem, a path is defined as any sequence of nodes from some
# starting node to any node in the tree along the parent-child connections. The
# path must contain at least one node and does not need to go through the
# root.
#
# Example 1:
#
#
# Input: [1,2,3]
#
# ⁠      1
# ⁠     / \
# ⁠    2   3
#
# Output: 6
#
#
# Example 2:
#
#
# Input: [-10,9,20,null,null,15,7]
#
# -10
# / \
# 9  20
# /  \
# 15   7
#
# Output: 42
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


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        res = -inf

        def max_sequence_sum(root: TreeNode) -> int:
            if not root:
                return 0
            left_max_sequence = max_sequence_sum(root.left)
            val = root.val
            right_max_sequence = max_sequence_sum(root.right)
            nonlocal res
            res = max(res, left_max_sequence + val + right_max_sequence)
            return max(0, left_max_sequence + val, val + right_max_sequence)

        max_sequence_sum(root)
        return res


# @lc code=end
