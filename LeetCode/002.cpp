struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode();
        ListNode *current = ans;
        int carry = 0;
        for (; l1 != nullptr || l2 != nullptr || carry > 0;) {
            int temp = carry;
            if (l1 != nullptr) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                temp += l2->val;
                l2 = l2->next;
            }
            carry = temp / 10;
            current->next = new ListNode(temp % 10);
            current = current->next;
        }
        return ans->next;
    }
};
