/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.71%)
 * Likes:    4272
 * Dislikes: 424
 * Total Accepted:    650K
 * Total Submissions: 1.9M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    const int N = size(nums);
    int left = 0, right = N;
    while (left != right) {
      int mid = left + (right - left >> 1);
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target <= nums[mid]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[0] <= target || target <= nums[mid]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
    }
    return right != N && nums[right] == target ? right : -1;
  }
};
// @lc code=end
