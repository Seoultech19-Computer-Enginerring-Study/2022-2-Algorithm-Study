#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;
  a = ' ' + a;
  b = ' ' + b;
  for (int i = 1; i < a.size(); i++) {
    for (int j = 1; j < b.size(); j++) {
      dp[i][j] =
          max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (a[i] == b[j])});
    }
  }
  cout << dp[a.size() - 1][b.size() - 1];
}