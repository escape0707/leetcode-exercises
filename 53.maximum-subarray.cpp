/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.58%)
 * Likes:    6821
 * Dislikes: 307
 * Total Accepted:    865.2K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int ret = numeric_limits<int>::min();
    accumulate(cbegin(nums), cend(nums), 0,
               [&ret](const int prev, const int curr) {
                 const int partial = prev > 0 ? prev + curr : curr;
                 ret = max(ret, partial);
                 return partial;
               });
    return ret;
  }
};
// @lc code=end
