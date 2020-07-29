#
# @lc app=leetcode id=621 lang=python3
#
# [621] Task Scheduler
#
# https://leetcode.com/problems/task-scheduler/description/
#
# algorithms
# Medium (48.75%)
# Likes:    3444
# Dislikes: 702
# Total Accepted:    188.4K
# Total Submissions: 378.6K
# Testcase Example:  '["A","A","A","B","B","B"]\n2'
#
# You are given a char array representing tasks CPU need to do. It contains
# capital letters A to Z where each letter represents a different task. Tasks
# could be done without the original order of the array. Each task is done in
# one unit of time. For each unit of time, the CPU could complete either one
# task or just be idle.
#
# However, there is a non-negative integer n that represents the cooldown
# period between two same tasks (the same letter in the array), that is that
# there must be at least n units of time between any two same tasks.
#
# You need to return the least number of units of times that the CPU will take
# to finish all the given tasks.
#
#
# Example 1:
#
#
# Input: tasks = ["A","A","A","B","B","B"], n = 2
# Output: 8
# Explanation:
# A -> B -> idle -> A -> B -> idle -> A -> B
# There is at least 2 units of time between any two same tasks.
#
#
# Example 2:
#
#
# Input: tasks = ["A","A","A","B","B","B"], n = 0
# Output: 6
# Explanation: On this case any permutation of size 6 would work since n = 0.
# ["A","A","A","B","B","B"]
# ["A","B","A","B","A","B"]
# ["B","B","B","A","A","A"]
# ...
# And so on.
#
#
# Example 3:
#
#
# Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
# Output: 16
# Explanation:
# One possible solution is
# A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle
# -> idle -> A
#
#
#
# Constraints:
#
#
# The number of tasks is in the range [1, 10000].
# The integer n is in the range [0, 100].
#
#
#

from bisect import *
from collections import *
from functools import *
from heapq import *
from itertools import *
from math import *
from operator import *
from typing import *


# @lc code=start
class Solution:
    # def leastInterval(self, tasks: List[str], n: int) -> int:
    #     heap_negated = list(-count for count in Counter(tasks).values())
    #     heapify(heap_negated)
    #     que: Deque[Tuple[int, int]] = deque()
    #     time = 0
    #     while heap_negated or que:
    #         if heap_negated:
    #             remaining_task_count_negated = heappop(heap_negated)
    #             remaining_task_count_negated += 1
    #             if remaining_task_count_negated != 0:
    #                 que.append((time + 1 + n, remaining_task_count_negated))
    #         time += 1
    #         if que and que[0][0] == time:
    #             heappush(heap_negated, que.popleft()[1])
    #     return time

    def leastInterval(self, tasks: List[str], n: int) -> int:
        task_count_collection = tuple(Counter(tasks).values())
        max_cnt = max(task_count_collection)
        max_freq = task_count_collection.count(max_cnt)
        return max(len(tasks), (max_cnt - 1) * (n + 1) + max_freq)


# @lc code=end
