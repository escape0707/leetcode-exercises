/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.50%)
 * Likes:    3716
 * Dislikes: 121
 * Total Accepted:    225.2K
 * Total Submissions: 516.5K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 *
 *
 * Note:
 *
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 *
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> counter = {{0, 1}};
    int result = 0, prefixsum = 0;
    for (const int num : nums) {
      prefixsum += num;
      result += counter[prefixsum - k];
      counter[prefixsum] += 1;
    }
    return result;
  }
};
// @lc code=end
