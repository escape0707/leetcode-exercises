/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (48.83%)
 * Likes:    1728
 * Dislikes: 374
 * Total Accepted:    407.1K
 * Total Submissions: 815.1K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 
 *
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        auto next_of = [](int num) {
            int ret = 0;
            while (num) {
                ret += static_cast<int>(pow(num % 10, 2));
                num /= 10;
            }
            return ret;
        };
        int slow = n, fast = n;
        do {
            slow = next_of(slow);
            fast = next_of(next_of(fast));
        } while (slow != fast);
        return slow == 1;
    }
};
// @lc code=end
