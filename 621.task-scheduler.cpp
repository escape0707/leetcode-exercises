/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (48.75%)
 * Likes:    3444
 * Dislikes: 702
 * Total Accepted:    188.4K
 * Total Submissions: 378.6K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * You are given a char array representing tasks CPU need to do. It contains
 * capital letters A to Z where each letter represents a different task. Tasks
 * could be done without the original order of the array. Each task is done in
 * one unit of time. For each unit of time, the CPU could complete either one
 * task or just be idle.
 *
 * However, there is a non-negative integer n that represents the cooldown
 * period between two same tasks (the same letter in the array), that is that
 * there must be at least n units of time between any two same tasks.
 *
 * You need to return the least number of units of times that the CPU will take
 * to finish all the given tasks.
 *
 *
 * Example 1:
 *
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation:
 * A -> B -> idle -> A -> B -> idle -> A -> B
 * There is at least 2 units of time between any two same tasks.
 *
 *
 * Example 2:
 *
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 0
 * Output: 6
 * Explanation: On this case any permutation of size 6 would work since n = 0.
 * ["A","A","A","B","B","B"]
 * ["A","B","A","B","A","B"]
 * ["B","B","B","A","A","A"]
 * ...
 * And so on.
 *
 *
 * Example 3:
 *
 *
 * Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
 * Output: 16
 * Explanation:
 * One possible solution is
 * A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle
 * -> idle -> A
 *
 *
 *
 * Constraints:
 *
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
static auto speedup = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  // int leastInterval(vector<char> &tasks, int n) {
  //   // Make max heap and cooldown queue.
  //   unordered_map<char, int> counter;
  //   for (const char c : tasks) {
  //     ++counter[c];
  //   }
  //   vector<int> task_count_collection;
  //   task_count_collection.reserve(size(counter));
  //   for (const auto &p : counter) {
  //     task_count_collection.push_back(p.second);
  //   }
  //   priority_queue<int> heap(less<int>(), move(task_count_collection));
  //   queue<pair<int, int>> que;

  //   int current_time = 0;
  //   while (!heap.empty() || !que.empty()) {
  //     if (!heap.empty()) {
  //       int remaining_task_count = heap.top();
  //       heap.pop();
  //       --remaining_task_count;
  //       if (remaining_task_count != 0) {
  //         que.emplace(current_time + 1 + n, remaining_task_count);
  //       }
  //     }

  //     ++current_time;

  //     if (!que.empty() && que.front().first == current_time) {
  //       heap.push(que.front().second);
  //       que.pop();
  //     }
  //   }
  //   return current_time;
  // }

  int leastInterval(vector<char> &tasks, int n) {
    array<int, 26> cnt = {};
    for (const char c : tasks) {
      ++cnt[c - 'A'];
    }
    const int max_cnt = *max_element(cbegin(cnt), cend(cnt));
    const int max_freq = count(cbegin(cnt), cend(cnt), max_cnt);
    cout << max_cnt << n << max_freq << endl;
    return max(static_cast<int>(size(tasks)),
               (max_cnt - 1) * (n + 1) + max_freq);
  }
};

// @lc code=end
