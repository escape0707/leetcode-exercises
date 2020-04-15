/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (58.46%)
 * Likes:    4063
 * Dislikes: 347
 * Total Accepted:    436.1K
 * Total Submissions: 738K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Example:
 *
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 *
 * Constraint: It's guaranteed that the product of the elements of any prefix
 * or suffix of the array (including the whole array) fits in a 32 bit
 * integer.
 *
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> ret = {1};
    partial_sum(cbegin(nums), cend(nums) - 1, back_inserter(ret),
                multiplies<int>());
    {
      int suf = 1;
      auto it = rbegin(ret) + 1;
      for (auto rb = crbegin(nums), re = crend(nums) - 1; rb != re;
           ++rb, ++it) {
        suf *= *rb;
        *it *= suf;
      }
    }
    return ret;
  }
};
// @lc code=end
