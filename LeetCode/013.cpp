// LeetCode 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    const vector<string> vec = {"IV", "IX", "XL", "XC", "CD", "CM"};
    inline const int tr(string s) {
        for (const auto &x : vec) {
            if (x == s) {
                char c = s[0];
                if (c == 'I') {
                    return 1;
                } else if (c == 'X') {
                    return 10;
                } else {
                    return 100;
                }
            }
        }
        return 0;
    }
    inline const int add(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    int romanToInt(string s) {
        s.push_back('A');
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            string curr(1, s[i]);
            curr += s[i + 1];
            int k = tr(curr);
            ans -= k << 1;
            ans += add(s[i]);
        }
        return ans;
    }
};
