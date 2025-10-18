#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {

      if (!head) return false;

      ListNode* first = head;
      ListNode* second = head;

      while (first && second) {
        first = first->next;

        if (second->next) {
          second = second->next->next;
        }
        else {
          break;
        }

        if (first == second) {
          return true;
        }
      }

      return false;
    }
};

