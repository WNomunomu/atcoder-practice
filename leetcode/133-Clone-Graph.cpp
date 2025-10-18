#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node* cloneGraph(Node* node) {
      if (node == nullptr) {
        return nullptr;
      }
      
      Node* head = new Node(node->val);

      unordered_map<int, Node*> createdNode;
      createdNode[head->val] = head;

      cloneGraph(node, head, createdNode);

      return head;
    }
  private:
    void cloneGraph(Node*& originalNode, Node*& clonedNode, unordered_map<int, Node*>& createdNode) {
      for (Node*& neighbor : originalNode->neighbors) {
        if (!createdNode.contains(neighbor->val)) {
          Node* newNode = new Node(neighbor->val);
          clonedNode->neighbors.push_back(newNode);
          createdNode[newNode->val] = newNode;
          cloneGraph(neighbor, newNode, createdNode);
        }
        else {
          clonedNode->neighbors.push_back(createdNode[neighbor->val]);
        }
      }
    }
};

