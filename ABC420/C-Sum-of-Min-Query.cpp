#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  
  vector<long long> A(n);
  vector<long long> B(n);
  vector<long long> Min(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  long long count = 0;

  for (int i = 0; i < n; i++) {
    cin >> B[i];
    Min[i] = min(A[i], B[i]);
    count += Min[i];
  }

  int prev;

  for (int i = 0; i < q; i++) {
    char c;
    int x;
    long long v;
    cin >> c >> x >> v;

    if (c == 'A') {
      A[x - 1] = v;      
      prev = Min[x - 1];    
      Min[x - 1] = min(A[x - 1], B[x - 1]);
      count = count - prev + Min[x - 1];
    }
    else if (c == 'B') {
      B[x - 1] = v;
      prev = Min[x - 1];
      Min[x - 1] = min(A[x - 1], B[x - 1]);
      count = count + Min[x - 1] - prev;
    }

    cout << count << endl;
  }
  return 0;
}
