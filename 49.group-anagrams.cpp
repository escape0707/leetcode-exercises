/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (52.44%)
 * Likes:    2767
 * Dislikes: 157
 * Total Accepted:    525.5K
 * Total Submissions: 979.7K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        const int N = size(strs);
        unordered_map<string, vector<string>> groups;
        for (string &str : strs) {
            groups[sorted_str(str)].push_back(move(str));
        }
        vector<vector<string>> ret;
        ret.reserve(N);
        for (auto &p : groups) {
            ret.push_back(move(p.second));
        }
        return ret;
    }

private:
    static string sorted_str(const string &str) {
        static array<int, 26> counts;
        counts.fill(0);
        for (const char c : str) {
            ++counts[c - 97];
        }
        string ret;
        ret.reserve(size(str));
        char c = 97;
        for (const int count : counts) {
            fill_n(back_inserter(ret), count, c);
            ++c;
        }
        return ret;
    }
};
// @lc code=end
