/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (41.38%)
 * Likes:    1033
 * Dislikes: 232
 * Total Accepted:    199.8K
 * Total Submissions: 482.8K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5]
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: [2,2,2,0,1]
 * Output: 0
 *
 * Note:
 *
 *
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int findMin(const vector<int> &nums) {
    return findMinInRange(nums, 0, size(nums) - 1);
  }

 private:
  int findMinInRange(const vector<int> &nums, int left, int right) {
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
        return min(findMinInRange(nums, left, mid),
                   findMinInRange(nums, mid, right));
      }
      if (nums[mid] > nums[right]) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return min(nums[left], nums[right]);
  }
};
// @lc code=end
