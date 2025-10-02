#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  long long shiftCount = 0;

  for (int i = 0; i < n; i++) {
    A[i] = i + 1;
  }

  
  for (int i = 0; i < q; i++) {
    int command;
    cin >> command;
    
    if (command == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      int shiftedP = (p + shiftCount) % n;
      A[shiftedP] = x;
    }
    else if (command == 2) {
      int p;
      cin >> p;
      p--;
      int shiftedP = (p + shiftCount) % n;
      cout << A[shiftedP] << endl;
    }
    else if (command == 3) {
      int k;
      cin >> k;
      shiftCount += k;
      shiftCount %= n;
    }
  }
  
  return 0;
}

