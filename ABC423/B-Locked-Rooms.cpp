#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> doors;
  for (int i = 0; i < N; i++) {
    int doorLocked;
    cin >> doorLocked;
    doors.push_back(doorLocked);
  }

  int a = 0;
  int b = 0;

  for (int i = 0; i < N; i++) {
    if (doors[i]) {
      a = i;
      break;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    if (doors[i]) {
      b = i;
      break;
    }
  }

  cout << b - a << endl;

  return 0;
}
