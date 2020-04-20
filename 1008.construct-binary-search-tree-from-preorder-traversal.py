#
# @lc app=leetcode id=1008 lang=python3
#
# [1008] Construct Binary Search Tree from Preorder Traversal
#
# https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#
# algorithms
# Medium (75.43%)
# Likes:    666
# Dislikes: 21
# Total Accepted:    47.2K
# Total Submissions: 62.2K
# Testcase Example:  '[8,5,1,7,10,12]'
#
# Return the root node of a binary search tree that matches the given preorder
# traversal.
#
# (Recall that a binary search tree is a binary tree where for every node, any
# descendant of node.left has a value < node.val, and any descendant of
# node.right has a value > node.val.  Also recall that a preorder traversal
# displays the value of the node first, then traverses node.left, then
# traverses node.right.)
#
#
#
# Example 1:
#
#
# Input: [8,5,1,7,10,12]
# Output: [8,5,10,1,7,null,12]
#
#
#
#
#
# Note:
#
#
# 1 <= preorder.length <= 100
# The values of preorder are distinct.
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
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        current = root = TreeNode(inf)
        stack: Deque[TreeNode] = deque()
        stack.append(current)
        for val in preorder:
            new_node = TreeNode(val)
            if val < current.val:
                current.left = new_node
                stack.append(current)
            else:
                while val >= stack[-1].val:
                    current = stack.pop()
                if val == current.val:
                    raise ValueError("Duplicate values in preorder.")
                current.right = new_node
            current = new_node
        return root.left


# @lc code=end
