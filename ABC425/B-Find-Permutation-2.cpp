#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A;
  vector<bool> isUsed(n + 1);
 
  bool flag = false;
  
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a != -1) {
      if (isUsed[a]) {
        flag = true;
      }
      isUsed[a] = true;
    }
    A.push_back(a);
  }

  if (flag) {
    cout << "No" << endl;
  }
  else {
    int count = 1;

    for (int i = 0; i < n; i++) {
      if (A[i] == -1) {
        while (isUsed[count]) {
          count++;
        }
        A[i] = count;
        isUsed[count] = true;
        count++;
      }
    } 

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        cout << " ";
      }
      cout << A[i];
    }
    cout << endl;
  }

    
  return 0;
}
