/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (35.65%)
 * Likes:    2439
 * Dislikes: 63
 * Total Accepted:    207.3K
 * Total Submissions: 575.5K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty() or matrix.front().empty()) {
      return 0;
    }
    vector<int> top;
    const int N = size(matrix.front());
    top.reserve(N);
    for (const char &c : matrix.front()) {
      top.push_back(c == '1');
    }
    vector<int> dp = top;
    int max_edge_length = *max_element(cbegin(dp), cend(dp));
    for (auto b = cbegin(matrix) + 1, e = cend(matrix); b != e; ++b) {
      const vector<char> &row = *b;
      int left = row.front() == '1';
      int prev = dp.front();
      dp.front() = left;
      max_edge_length = max(max_edge_length, left);
      for (int j = 1; j < N; ++j) {
        int num = row[j] == '1';
        int cache = dp[j];
        dp[j] = num ? min({prev, left, top[j]}) + 1 : 0;
        max_edge_length = max(max_edge_length, dp[j]);
        prev = cache;
        left = num ? left + 1 : 0;
        top[j] = num ? top[j] + 1 : 0;
      }
    }
    return max_edge_length * max_edge_length;
  }
};
// @lc code=end
