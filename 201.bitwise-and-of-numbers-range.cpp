/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (37.23%)
 * Likes:    624
 * Dislikes: 87
 * Total Accepted:    99K
 * Total Submissions: 266.3K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 *
 * Example 1:
 *
 *
 * Input: [5,7]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1]
 * Output: 0
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    for (; m != n; ++i) {
      m >>= 1;
      n >>= 1;
    }
    return n << i;
  }
};
// @lc code=end
