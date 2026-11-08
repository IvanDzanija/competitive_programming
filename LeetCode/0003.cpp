#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int slow = 0, ans = 0;
        std::array<bool, 256> seen = {0};
        int i = 0;
        for (; i < s.size(); ++i) {
            char c = s[i];
            if (seen[(int)c]) {
                ans = max(ans, i - slow);
                while (s[slow] != c) {
                    char k = s[slow];
                    seen[(int)k] = false;
                    ++slow;
                }
                ++slow;
                // ans = max(ans, i - slow +1);
            } else {
                seen[(int)c] = true;
            }
        }
        i -= 1;
        ans = max(ans, i - slow + 1);
        return ans;
    }
};
