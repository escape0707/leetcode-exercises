/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.22%)
 * Likes:    1129
 * Dislikes: 63
 * Total Accepted:    113.4K
 * Total Submissions: 239.1K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 *
 *
 * Example 1:
 *
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 *
 *
 * Example 2:
 *
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 *
 *
 * Example 3:
 *
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 *
 *
 *
 * Example 4:
 *
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 *
 *
 * Follow up:
 *
 *
 * Can you solve it in O(N) time and O(1) space?
 *
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
  bool backspaceCompare(string S, string T) {
    auto SS = BackspacedRange(S);
    auto TT = BackspacedRange(T);
    return equal(SS.b, SS.e, TT.b, TT.e);
  }

 private:
  class BackspacedRange {
   public:
    class BackspacedIterator {
      using wrapped_iterator = reverse_iterator<string::const_iterator>;
      wrapped_iterator b, e;

     public:
      using iterator_category = input_iterator_tag;
      using value_type = iterator_traits<wrapped_iterator>::value_type;
      using difference_type =
          iterator_traits<wrapped_iterator>::difference_type;
      using pointer = iterator_traits<wrapped_iterator>::pointer;
      using reference = iterator_traits<wrapped_iterator>::reference;
      BackspacedIterator(wrapped_iterator _b, wrapped_iterator _e)
          : b(_b), e(_e) {
        flushBackspaces();
      }
      explicit BackspacedIterator(wrapped_iterator _e)
          : BackspacedIterator(_e, _e) {}
      BackspacedIterator &operator++() {
        // if (b == e) {
        //   return *this;
        // }
        // just let it be undefined behavior AS DESIGNED!!!
        // The default-constructed std::istream_iterator is known as the
        // end-of-stream iterator. When a valid std::istream_iterator reaches
        // the end of the underlying stream, it becomes equal to the
        // end-of-stream iterator. Dereferencing or incrementing it further
        // invokes undefined behavior.
        ++b;
        flushBackspaces();
        return *this;
      }
      BackspacedIterator operator++(int) {
        BackspacedIterator ret = *this;
        ++*this;
        return ret;
      }
      bool operator==(BackspacedIterator other) const {
        return b == other.b;
      }
      bool operator!=(BackspacedIterator other) const {
        return !(*this == other);
      }
      value_type operator*() const {
        // return b != e ? *b : '\0';
        // just let it be undefined behavior AS DESIGNED!!!
        // The default-constructed std::istream_iterator is known as the
        // end-of-stream iterator. When a valid std::istream_iterator reaches
        // the end of the underlying stream, it becomes equal to the
        // end-of-stream iterator. Dereferencing or incrementing it further
        // invokes undefined behavior.
        return *b;
      }

     private:
      void flushBackspaces() {
        static int hashtagCount;
        for (hashtagCount = 0; b != e; ++b) {
          if (*b == '#') {
            ++hashtagCount;
            continue;
          }
          if (hashtagCount) {
            --hashtagCount;
            continue;
          }
          return;
        }
      }
    };
    explicit BackspacedRange(const string &s)
        : b(crbegin(s), crend(s)), e(crend(s)) {}
    BackspacedIterator b, e;
  };
};
// @lc code=end
