/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (62.74%)
 * Likes:    343
 * Dislikes: 226
 * Total Accepted:    63.1K
 * Total Submissions: 100.4K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 *
 *
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> sortArray(vector<int> &nums) {
    quick_sort(nums);
    return nums;
  }

 private:
  using container_type = vector<int>;
  using iterator = container_type::iterator;

  static void my_shuffle(const iterator first, const iterator last) {
    // shuffle(first, last, default_random_engine(random_device()()));
    // return;
    const auto N = last - first;
    default_random_engine g((random_device()()));
    using distr_t = uniform_int_distribution<size_t>;
    using param_t = typename distr_t::param_type;
    distr_t D;
    for (auto i = N - 1; i > 0; --i) {
      swap(first[i], first[D(g, param_t(0, i))]);
    }
  }

  static void quick_sort(const iterator first, const iterator last) {
    if (last - first < 10) {
      // We can just return and delay insertion_sort till all quick_sort are
      // finished.
      // insertion_sort(first, last);
      return;
    }
    auto b = first;
    auto e = last;
    for (auto i = b; i != e;) {
      if (*i == *b) {
        ++i;
      } else if (*i < *b) {
        swap(*i++, *b++);
      } else {  // (*i > *b)
        swap(*i, *--e);
      }
    }
    quick_sort(first, b);
    quick_sort(e, last);
  }

  static void quick_sort(container_type &c) {
    my_shuffle(begin(c), end(c));
    quick_sort(begin(c), end(c));
    insertion_sort(begin(c), end(c));
  }

  template <typename Compare = less<int>>
  static void merge_sort(iterator first, const iterator last,
                         iterator aux_first, Compare comp = {}) {
    const auto N = last - first;
    if (N < 10) {
      insertion_sort(first, last);
      return;
    }
    const auto mid = first + (N >> 1);
    const auto aux_mid = aux_first + (N >> 1), aux_last = aux_first + N;
    merge_sort(aux_first, aux_mid, first);
    merge_sort(aux_mid, aux_last, mid);
    for (auto &i = aux_first, j = aux_mid, &k = first; k != last; ++k) {
      if (i == aux_mid) {
        *k = *j++;
      } else if (j == aux_last) {
        *k = *i++;
      } else if (comp(*i, *j)) {
        *k = *i++;
      } else {
        *k = *j++;
      }
    }
  }

  static void merge_sort(container_type &c) {
    container_type aux = c;
    merge_sort(begin(c), end(c), begin(aux));
  }

  static container_type merge_sorted(container_type &c) {
    container_type aux = c;
    merge_sort(begin(aux), end(aux), begin(c));
    return aux;
  }

  template <typename Compare = less<int>>
  static void shell_sort(const iterator first, const iterator last,
                         Compare comp = {}) {
    const auto N = last - first;
    decltype(last - first) h = 1;
    while (h < N / 3) {
      h = h * 3 + 1;
    }
    while (h > 0) {
      for (auto i = first + h; i != last; ++i) {
        for (auto j = i; j - h >= first && comp(*j, *(j - h)); j -= h) {
          swap(*j, *(j - h));
        }
      }
      h /= 3;
    }
  }

  static void shell_sort(container_type &c) {
    shell_sort(begin(c), end(c));
  }

  template <typename Compare = less<int>>
  static void insertion_sort(const iterator first, const iterator last,
                             Compare comp = {}) {
    for (auto i = first + 1; i != last; ++i) {
      for (auto j = i; j != first && comp(*j, *(j - 1)); --j) {
        swap(*j, *(j - 1));
      }
    }
  }

  static void insertion_sort(container_type &c) {
    insertion_sort(begin(c), end(c));
  }
};
// @lc code=end
