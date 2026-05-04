#include <bits/stdc++.h>
using namespace std;

class Solution {
  using ll = int64_t;

 public:
  string longestPalindrome(string s) {
    ll n = s.size();
    ll ans = 0, st = 0, fn = 0;

    for (ll i = 0; i < n; ++i) {
      for (ll d = 1;; ++d) {
        ll left = i - d;
        ll right = i + d;
        if (left < 0 || d >= n) {
          break;
        }
        if (s[left] != s[right]) {
          break;
        }
        if (d > ans) {
          ans = d;
          st = left;
          fn = right;
        }
      }
    }

    for (ll i = 0; i < n; ++i) {
      for (ll d = 1;; ++d) {
        ll left = i - d + 1;
        ll right = i + d;
        if (left < 0 || d >= n) {
          break;
        }
        if (s[left] != s[right]) {
          break;
        }
        if (d > ans) {
          ans = d;
          st = left;
          fn = right;
        }
      }
    }
    return s.substr(st, fn - st + 1);
  }
};
