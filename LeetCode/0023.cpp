#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ans = nullptr;

    int n = lists.size();
    int finished = 0;
    priority_queue<pair<int, ListNode *>> pq;
    for (int i = 0; i < n; ++i) {
      auto curr = lists[i];
      if (curr == nullptr) {
        ++finished;
        continue;
      }
      pq.push(make_pair(-curr->val, curr));
    }

    ListNode *res = nullptr;
    while (finished != n) {
      auto [val, ptr] = pq.top();
      pq.pop();
      if (ptr->next == nullptr) {
        ++finished;
      } else {
        auto next = ptr->next;
        pq.push(make_pair(-next->val, next));
      }

      auto node = ptr;
      if (res == nullptr) {
        res = node;
        ans = node;
      } else {
        res->next = node;
        res = res->next;
      }
    }
    if (res != nullptr) {
      res->next = nullptr;
    }
    return ans;
  }
};
