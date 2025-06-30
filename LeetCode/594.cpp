#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findLHS(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        bool first = true;
        int curr = 1, next = 1;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                ++curr;
                ++next;

            } else {

                if (nums[i] - 1 == nums[i - 1]) {
                    curr = next + 1;
                    next = 1;
                } else {
                    curr = next = 1;
                }
            }

            if (next < curr) {
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};
