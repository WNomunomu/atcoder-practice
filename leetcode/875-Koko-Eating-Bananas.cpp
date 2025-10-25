#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool canFinish(vector<int>& piles, int k, int h) {
      long long hours = 0;
      for (int& pile : piles) {
        hours += pile / k;
        if (pile % k != 0) hours++;

        if (hours > h) return false;
      }

      return hours <= h;
    }
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int maxK = *max_element(piles.begin(), piles.end());
      int minK = 1;

      int ng = 0;
      int ok = maxK + 1;

      while (ok - ng > 1) {
        int mid = (ng + ok) / 2;

        if (canFinish(piles, mid, h)) {
          ok = mid;
        }
        else {
          ng = mid;
        }
      }

      return ok;
    }
};

