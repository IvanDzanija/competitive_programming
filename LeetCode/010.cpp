#include <bits/stdc++.h>
using namespace std;

class Solution {
  using ll = int64_t;

 public:
  string ss, pp;
  map<pair<int, int>, bool> memo;
  bool match(int i, int j) {
    pair<int, int> key = {i, j};
    if (memo.count({i, j})) {
      return memo[key];
    }
    if (i >= ss.size() && j >= pp.size()) {
      memo[key] = true;
      return true;
    } else if (i >= ss.size()) {
      if ((pp.size() - j) == 1 && pp[j] == '*') {
        memo[key] = true;
        return true;
      }
      if ((pp.size() - j) % 2 == 1) {
        memo[key] = false;
        return false;
      }
      for (++j; j < pp.size(); j += 2) {
        if (pp[j] != '*') {
          memo[key] = false;
          return false;
        }
      }
      memo[key] = true;
      return true;
    } else if (j >= pp.size()) {
      memo[key] = false;
      return false;
    }
    char currs = ss[i];
    char currp = pp[j];
    bool ans = false;
    bool fm = (currs == currp || currp == '.');

    if (j + 1 < pp.size() && pp[j + 1] == '*') {
      if (match(i, j + 2)) {
        memo[key] = true;
        return true;
      }
      if (fm && match(i + 1, j)) {
        memo[key] = true;
        return true;
      }

      memo[key] = false;
      return false;
    } else {
      if (fm) {
        memo[key] = match(i + 1, j + 1);
        return (memo[key]);
      }
      memo[key] = false;
      return false;
    }
    memo[key] = ans;
    return ans;
  }
  bool isMatch(string s, string p) {
    ss = s, pp = p;
    return match(0, 0);
  }
};
