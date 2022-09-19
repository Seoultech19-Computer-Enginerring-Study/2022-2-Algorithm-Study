#include <bits/stdc++.h>
using namespace std;
int d[100000][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  d[0][0] = 0;
  d[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> d[i][0];
    d[i][1] = d[i][0] + d[i - 1][1];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << d[b][1] - d[a - 1][1] << "\n";
  }
}