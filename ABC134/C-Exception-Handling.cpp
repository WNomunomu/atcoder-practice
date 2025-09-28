#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> A(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<int> Temp = A;
  sort(Temp.begin(), Temp.end(), greater<int>());

  int maxValue = Temp[0];
  int secondMaxValue = Temp[1];

  for (int i = 0; i < n; i++) {
    int a = A[i];
    if (a == maxValue) cout << secondMaxValue << endl;
    else {
      cout << maxValue << endl;
    }
  }

  return 0;
}
