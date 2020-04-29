/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (32.60%)
 * Likes:    2915
 * Dislikes: 243
 * Total Accepted:    300K
 * Total Submissions: 915.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 *
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 *
 * Output: 42
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    max_sequence_sum(root);
    return res;
  }

 private:
  int max_sequence_sum(const TreeNode *root) {
    if (!root) {
      return 0;
    }
    const int left_max_sequence = max_sequence_sum(root->left);
    const int val = root->val;
    const int right_max_sequence = max_sequence_sum(root->right);
    res = max(res, left_max_sequence + val + right_max_sequence);
    return max({0, left_max_sequence + val, val + right_max_sequence});
  }

  int res = numeric_limits<int>::min();
};
// @lc code=end
