#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end());

  long long result = 0;
  long long start = v[0].first, end = v[0].second;
  for (int i = 1; i < n; i++) {
    if (v[i].first > end) {
      result += end - start;
      start = v[i].first;
      end = v[i].second;
    } else if (v[i].first <= end && v[i].second > end) {
      end = v[i].second;
    }
  }
  result += end - start;
  cout << result;
}