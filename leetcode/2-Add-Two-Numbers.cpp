#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      bool isOvered = false;

      ListNode* dummy = new ListNode(0);
      ListNode* current = dummy;

      while (l1 || l2) {
        int nextValue;

        if (!l1) {
          nextValue = l2->val;
        }
        else if (!l2) {
          nextValue = l1->val;
        }
        else {
          nextValue = l1->val + l2->val;
        }

        if (isOvered) {
          nextValue += 1;
        }

        if (nextValue >= 10) {
          isOvered = true;
          ListNode* next = new ListNode((nextValue) % 10);
          current->next = next;
          current = current->next;
        }
        else {
          ListNode* next = new ListNode(nextValue);
          current->next = next;
          current = current->next;
          isOvered = false;
        }

        if (l1) {
          l1 = l1->next;
        }
        if (l2) {
          l2 = l2->next;
        }
      }

      if (isOvered) {
        ListNode* next = new ListNode(1);
        current->next = next;
      }

      return dummy->next;
    }
};

