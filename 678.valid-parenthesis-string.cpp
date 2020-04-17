/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (34.08%)
 * Likes:    1435
 * Dislikes: 45
 * Total Accepted:    81.9K
 * Total Submissions: 258.5K
 * Testcase Example:  '"()"'
 *
 *
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid. We define the
 * validity of a string by these rules:
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string.
 * An empty string is also valid.
 *
 *
 *
 * Example 1:
 *
 * Input: "()"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "(*)"
 * Output: True
 *
 *
 *
 * Example 3:
 *
 * Input: "(*))"
 * Output: True
 *
 *
 *
 * Note:
 *
 * The string size will be in the range [1, 100].
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkValidString(string s) {
    int lo = 0, hi = 0;
    for (const char c : s) {
      lo += (c == '(') ? 1 : -1;
      hi -= (c == ')') ? 1 : -1;
      if (hi < 0) {
        return false;
      }
      lo = max(lo, 0);
    }
    return lo == 0;
  }
};
// @lc code=end
