#include <bits/stdc++.h>
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
    void reorderList(ListNode* head) {
      vector<ListNode*> nodeList;

      ListNode* current = head;

      while (current) {
        nodeList.push_back(current);
        current = current->next;
      }

      int n = nodeList.size();

      for (int i = 0; i < n; i++) {
        if (i == n - 1) {
          nodeList[i]->next = nullptr;
        }
        else if (i % 2 == 0) {
          nodeList[i / 2]->next = nodeList[n - i / 2 - 1];
        }
        else {
          nodeList[n - i / 2 - 1]->next = nodeList[i / 2 + 1];
        }
      }
    }
};

