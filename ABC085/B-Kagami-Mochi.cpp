#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> riceCakes(n);
  for (int i = 0; i < n; i++) {
    cin >> riceCakes[i];
  }

  sort(riceCakes.begin(), riceCakes.end());

  int count = 0;
  int prev = -1;
  for (int riceCake : riceCakes) {
    if (prev != riceCake) {
      count++;
    }
    prev = riceCake;
  } 

  cout << count << endl;

  return 0;
}
