#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  for (int i = 0; i < n - 1; i++) {
    vector<int> temp = A;

    for (int j = 0; j < n; j++) {
      if (j - 1 >= 0) A[j] += temp[j - 1];
      if (j + 1 < n) A[j] += temp[j + 1];
      A[j] %= 100;
    }
  }

  cout << A[n - 1] << endl;
  return 0;
}

