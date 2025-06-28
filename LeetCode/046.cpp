#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n;
    vector<int> perm;
    vector<vector<int>> perms;
    vector<bool> chosen;
    vector<int> _nums;
    void search() {
        if (perm.size() == n) {
            perms.push_back(perm);
        } else {
            for (int i = 0; i < n; ++i) {
                if (chosen[i]) {
                    continue;
                }
                perm.push_back(_nums[i]);
                chosen[i] = true;
                search();
                chosen[i] = false;
                perm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        _nums = nums;
        n = nums.size();
        chosen.resize(n);
        search();
        return perms;
    }
};
