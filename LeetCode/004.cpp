// Leetcode 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#pragma once
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int combined_len = (int)nums1.size() + (int)nums2.size();
        int target = combined_len / 2 + 1;
        if (nums1.size() == 0) {
            if (nums2.size() & 1) {
                return nums2[nums2.size() / 2];
            } else {
                return (double)(nums2[nums2.size() / 2] +
                                nums2[nums2.size() / 2 - 1]) /
                       2;
            }
        }

        if (nums2.size() == 0) {
            if (nums1.size() & 1) {
                return nums1[nums1.size() / 2];
            } else {
                return (double)(nums1[nums1.size() / 2] +
                                nums1[nums1.size() / 2 - 1]) /
                       2;
            }
        }
        if (combined_len & 1) {
            int low = 0, high = nums1.size() - 1;
            while (low <= high) {
                int mid = (high + low) / 2;
                int pos = mid + 1;
                auto it = upper_bound(nums2.begin(), nums2.end(), nums1[mid]);
                int merged = std::distance(nums2.begin(), it);
                if (merged + pos == target) {
                    return nums1[mid];
                } else if (merged + pos > target) {
                    high = mid - 1;

                } else {
                    low = mid + 1;
                }
            }
            low = 0, high = nums2.size() - 1;
            while (low <= high) {
                int mid = (high + low) / 2;
                int pos = mid + 1;
                auto it = lower_bound(nums1.begin(), nums1.end(), nums2[mid]);
                int merged = std::distance(nums1.begin(), it);
                if (merged + pos == target) {
                    return nums2[mid];
                } else if (merged + pos > target) {
                    high = mid - 1;

                } else {
                    low = mid + 1;
                }
            }
        } else {
            --target;
            int low = 0, high = nums1.size() - 1;
            while (low <= high) {
                int mid = (high + low) / 2;
                int pos = mid + 1;
                auto it = upper_bound(nums2.begin(), nums2.end(), nums1[mid]);
                int merged = std::distance(nums2.begin(), it);
                if (merged + pos == target) {
                    if (it == nums2.end()) {
                        return (double)(nums1[mid] + nums1[mid + 1]) / 2;
                    } else if (mid == nums1.size() - 1) {
                        return (double)(nums1[mid] + *it) / 2;
                    } else {
                        return (double)(nums1[mid] + min(nums1[mid + 1], *it)) /
                               2;
                    }
                } else if (merged + pos > target) {
                    high = mid - 1;

                } else {
                    low = mid + 1;
                }
            }
            low = 0, high = nums2.size() - 1;
            while (low <= high) {
                int mid = (high + low) / 2;
                int pos = mid + 1;
                auto it = lower_bound(nums1.begin(), nums1.end(), nums2[mid]);
                int merged = std::distance(nums1.begin(), it);
                if (merged + pos == target) {
                    if (it == nums1.end()) {
                        return (double)(nums2[mid] + nums2[mid + 1]) / 2;
                    } else if (mid == nums2.size() - 1) {
                        return (double)(nums2[mid] + *it) / 2;
                    } else {
                        return (double)(nums2[mid] + min(nums2[mid + 1], *it)) /
                               2;
                    }
                } else if (merged + pos > target) {
                    high = mid - 1;

                } else {
                    low = mid + 1;
                }
            }
        }
        cout << "Wrong" << endl;
        return 0;
    }
};
