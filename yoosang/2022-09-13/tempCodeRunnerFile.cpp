#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1000005];
int b[1000005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int aidx = 0;
  int bidx = 0;
  vector<int> v;
  while (true) {
    if (aidx == n) v.push_back(b[bidx++]);
    if (bidx == m) v.push_back(a[aidx++]);

    if (a[aidx] < b[aidx]) {
      v.push_back(a[aidx++]);
    } else {
      v.push_back(b[bidx++]);
    }
    if (aidx == n && bidx == m) break;
  }
  for (auto i : v) {
    cout << i << ' ';
  }
}