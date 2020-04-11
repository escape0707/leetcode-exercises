#
# @lc app=leetcode id=543 lang=python3
#
# [543] Diameter of Binary Tree
#
# https://leetcode.com/problems/diameter-of-binary-tree/description/
#
# algorithms
# Easy (48.22%)
# Likes:    2392
# Dislikes: 151
# Total Accepted:    234.1K
# Total Submissions: 483.5K
# Testcase Example:  '[1,2,3,4,5]'
#
#
# Given a binary tree, you need to compute the length of the diameter of the
# tree. The diameter of a binary tree is the length of the longest path between
# any two nodes in a tree. This path may or may not pass through the root.
#
#
#
# Example:
# Given a binary tree
#
# ⁠         1
# ⁠        / \
# ⁠       2   3
# ⁠      / \
# ⁠     4   5
#
#
#
# Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
#
#
# Note:
# The length of path between two nodes is represented by the number of edges
# between them.
#
#

from collections import *
from functools import *
from itertools import *
from operator import *
from typing import *


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        ans: int

        def depth(node: TreeNode) -> int:
            nonlocal ans
            if not node:
                return 0
            depth_l = depth(node.left)
            depth_r = depth(node.right)
            ans = max(ans, depth_l + depth_r)
            return max(depth_l, depth_r) + 1

        ans = 0
        depth(root)
        return ans


# @lc code=end
