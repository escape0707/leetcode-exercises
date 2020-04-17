/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (45.22%)
 * Likes:    4595
 * Dislikes: 171
 * Total Accepted:    604.4K
 * Total Submissions: 1.3M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    const auto dfs = [&](const int i, const int j) {
      const auto dfs_impl = [&](const int i, const int j, const auto &dfs_ref) {
        if (!(0 <= i && i < size(grid) && 0 <= j && j < size(grid[i]) &&
              grid[i][j] == '1')) {
          return;
        }
        grid[i][j] = '0';
        static constexpr array<pair<int, int>, 4> direction = {
            {{-1, -0}, {0, +1}, {+1, 0}, {0, -1}}};
        for (const auto &dir : direction) {
          dfs_ref(i + dir.first, j + dir.second, dfs_ref);
        }
      };
      dfs_impl(i, j, dfs_impl);
    };

    int ret = 0;
    const int M = size(grid);
    for (int i = 0; i < M; ++i) {
      const int N = size(grid[i]);
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == '1') {
          ++ret;
          dfs(i, j);
        }
      }
    }
    return ret;
  }
};
// @lc code=end
