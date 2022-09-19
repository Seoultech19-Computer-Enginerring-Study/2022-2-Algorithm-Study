#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;
  for(int i; i<a.size();i++) {
    for(int j=0;j<b.size();j++){
      dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (a[i]==b[i])});
    }
  }
  cout<<dp[a.size()-1][b.size()-1];
}