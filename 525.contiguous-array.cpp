/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (44.75%)
 * Likes:    1283
 * Dislikes: 63
 * Total Accepted:    70.4K
 * Total Submissions: 165.9K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1.
 *
 *
 * Example 1:
 *
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 *
 *
 *
 * Note:
 * The length of the given binary array will not exceed 50,000.
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int findMaxLength(vector<int> &nums) {
    int ret = 0;
    const int sz = size(nums) + 1;
    vector<int> hashmap(sz, 0);
    int count = 0;
    {
      int i = 1;
      hashmap[count] = i;
      for (const int num : nums) {
        ++i;
        count += (num << 1) - 1;
        if (!hashmap[count]) {
          hashmap[count] = i;
        } else {
          ret = max(ret, i - hashmap[count]);
        }
      }
    }
    return ret;
  }
};
// @lc code=end
