/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (51.46%)
 * Likes:    2597
 * Dislikes: 54
 * Total Accepted:    384.8K
 * Total Submissions: 725.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    auto &grid_0 = grid.front();
    if (grid_0.empty()) {
      return 0;
    }
    partial_sum(cbegin(grid_0), cend(grid_0), begin(grid_0));
    const int M = size(grid);
    for (int i = 1; i < M; ++i) {
      auto &row = grid[i];
      row[0] += grid[i - 1].front();
      const int N = size(row);
      for (int j = 1; j < N; ++j) {
        row[j] += min(row[j - 1], grid[i - 1][j]);
      }
    }
    return grid.back().back();
  }
};
// @lc code=end
