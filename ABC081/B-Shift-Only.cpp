#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int count = 0;

  while(true) {
    bool flag = true;

    for (int i = 0; i < n; i++) {
      if (nums[i] % 2 == 1) {
        flag = false;
        break;
      }
      else {
        nums[i] = nums[i] / 2;
      }
    }

    if (flag) {
      count++;
    }
    else {
      break;
    }
  }
  cout << count << endl;

  return 0;
}
