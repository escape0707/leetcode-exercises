/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (41.87%)
 * Likes:    2830
 * Dislikes: 283
 * Total Accepted:    447.8K
 * Total Submissions: 1.1M
 * Testcase Example:
 '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MinStack {
 public:
  void push(int x) {
    if (min_stk.empty() || x <= min_stk.top()) {
      min_stk.push(x);
    }
    stk.push(x);
  }

  void pop() {
    if (stk.top() == min_stk.top()) {
      min_stk.pop();
    }
    stk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return min_stk.top();
  }

 private:
  stack<int> min_stk, stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
