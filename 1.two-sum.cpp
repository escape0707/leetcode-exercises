/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.07%)
 * Likes:    13483
 * Dislikes: 493
 * Total Accepted:    2.6M
 * Total Submissions: 5.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> occurred;
        const int N = size(nums);
        for (int i = 0; i < N; ++i) {
            const int num = nums[i];
            const auto pos = occurred.find(target - num);
            if (pos != end(occurred)) {
                return {pos->second, i};
            }
            occurred.emplace(num, i);
        }
        throw invalid_argument(nullptr);
    }
};
// @lc code=end
