#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = make_pair(nums[i], i);
        }
        sort(vec.begin(), vec.end());
        int low = 0, high = n - 1;
        int sum = vec[low].first + vec[high].first;
        while (sum != target) {
            if (sum < target) {
                ++low;
            } else {
                --high;
            }
            sum = vec[low].first + vec[high].first;
        }
        return {vec[low].second, vec[high].second};
    }
};
