#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool binarySearch(vector<int>& array, int target) {
      int n = array.size();

      int ng = -1;
      int ok = n;

      while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        if (array[mid] == target) {
          return true;
        }
        else if (array[mid] > target) {
          ok = mid;
        }
        else {
          ng = mid;
        }
      }
      
      return false;
    }
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();

      for (vector<int>& array : matrix) {
        bool result = binarySearch(array, target);     

        if (result) {
          return true;
        }
      }
      
      return false;
    }
};

