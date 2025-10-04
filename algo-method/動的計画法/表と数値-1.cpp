#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 4;

  vector<int> A;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  for (int i = 0; i < 3; i++) {
    vector<int> temp = A;
    
    for (int j = 0; j < n; j++) {
      if (j - 1 >= 0) A[j] += temp[j - 1];
      if (j + 1 <= 3) A[j] += temp[j + 1];
    }
  }

  cout << A[3] << endl;

  return 0;
}

