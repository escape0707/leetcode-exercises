/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 *
 * https://leetcode.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (26.08%)
 * Likes:    668
 * Dislikes: 70
 * Total Accepted:    15K
 * Total Submissions: 56.7K
 * Testcase Example:  '1\n2'
 *
 * You are given K eggs, and you have access to a building with N floors from 1
 * to N. 
 *
 * Each egg is identical in function, and if an egg breaks, you cannot drop it
 * again.
 *
 * You know that there exists a floor F with 0 <= F <= N such that any egg
 * dropped at a floor higher than F will break, and any egg dropped at or below
 * floor F will not break.
 *
 * Each move, you may take an egg (if you have an unbroken one) and drop it
 * from any floor X (with 1 <= X <= N). 
 *
 * Your goal is to know with certainty what the value of F is.
 *
 * What is the minimum number of moves that you need to know with certainty
 * what F is, regardless of the initial value of F?
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: K = 1, N = 2
 * Output: 2
 * Explanation:
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty
 * that F = 1.
 * If it didn't break, then we know with certainty F = 2.
 * Hence, we needed 2 moves in the worst case to know what F is with
 * certainty.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: K = 2, N = 6
 * Output: 3
 *
 *
 *
 * Example 3:
 *
 *
 * Input: K = 3, N = 14
 * Output: 4
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= K <= 100
 * 1 <= N <= 10000
 *
 *
 *
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int superEggDrop(int K, int N) {
    vector<int> canTryFloors(K + 1);
    for (int moves = 1; true; ++moves) {
      canTryFloors.back() += canTryFloors[K - 1] + 1;
      if (canTryFloors.back() >= N) {
        return moves;
      }
      for (int i = K - 1; i; --i) {
        canTryFloors[i] += canTryFloors[i - 1] + 1;
      }
    }
  }
};
// @lc code=end
