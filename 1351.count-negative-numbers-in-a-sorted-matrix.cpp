// @lc app=leetcode id=1351 lang=cpp

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        const int N = grid[0].size();
        int i = N - 1;
        for (const vector<int>& row : grid) {
            while (i >= 0 && row[i] < 0) {
                --i;
            }
            count += N - i - 1;
        }
        return count;
    }
};
// @lc code=end
