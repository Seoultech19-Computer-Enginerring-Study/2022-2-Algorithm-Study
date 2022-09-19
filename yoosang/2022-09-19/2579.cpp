#include <bits/stdc++.h>
using namespace std;
int d[305][3];
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> d[i][0];
  }
  d[1][1] = d[1][0];
  d[1][2] = 0;
  d[2][1] = d[2][0];
  d[2][2] = d[1][0] + d[2][0];
  for (int i = 3; i <= t; i++) {
    d[i][1] = max(d[i - 2][1], d[i - 2][2]) + d[i][0];
    d[i][2] = d[i - 1][1] + d[i][0];
  }
  cout << max(d[t][1], d[t][2]);
}