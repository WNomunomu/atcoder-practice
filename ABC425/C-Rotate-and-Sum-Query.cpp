#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  
  vector<long long> A(n);
  vector<long long> S(n + 1, 0);
  
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    S[i + 1] = S[i] + A[i];
  }
  
  int shiftCount = 0;
  
  for (int i = 0; i < q; i++) {
    int query;
    cin >> query;
    
    if (query == 1) {
      int c;
      cin >> c;
      shiftCount = (shiftCount + c) % n;
    } 
    else if (query == 2) {
      int l, r;
      cin >> l >> r;
      l--; r--;
      
      int start = (l + shiftCount) % n;
      int end = (r + shiftCount) % n;
      
      long long ans = 0;
      
      if (start <= end) {
        ans = S[end + 1] - S[start];
      }
      else {
        ans = (S[n] - S[start]) + S[end + 1];
      }
      
      cout << ans << endl;
    }
  }
  
  return 0;
}
