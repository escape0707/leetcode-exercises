/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (75.43%)
 * Likes:    666
 * Dislikes: 21
 * Total Accepted:    47.2K
 * Total Submissions: 62.2K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 *
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 *
 *
 *
 *
 *
 * Note: 
 *
 *
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    TreeNode *current = new TreeNode(numeric_limits<int>::max()),
             *root = current;
    stack<TreeNode *> stk;
    stk.push(root);
    for (const int val : preorder) {
      const auto new_node = new TreeNode(val);
      if (val < current->val) {
        current->left = new_node;
        stk.push(current);
      } else {
        while (val >= stk.top()->val) {
          current = stk.top();
          stk.pop();
        }
        if (val == current->val) {
          throw invalid_argument("Duplicate values in preorder.");
        }
        current->right = new_node;
      }
      current = new_node;
    }
    return root->left;
  }
};
// @lc code=end
