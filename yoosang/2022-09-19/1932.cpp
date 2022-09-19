#include <bits/stdc++.h>
using namespace std;
int d[505][505];
int arr[505][505];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> arr[i][j];
    }
  }
  d[1][1] = arr[1][1];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + arr[i][j];
    }
  }
  int result = 0;
  for (int i = 1; i <= n; i++) {
    result = max(d[n][i], result);
  }
  cout << result << "\n";
}