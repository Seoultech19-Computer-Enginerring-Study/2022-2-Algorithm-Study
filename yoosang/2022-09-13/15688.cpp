#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  
  
  cin.tie(0);
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n - 1 - i; j++) {
//       if (v[j] > v[j + 1]) {
//         int temp = v[j];
//         v[j] = v[j + 1];
//         v[j + 1] = temp;
//       }
//     }
//   }
  for (auto a : v) {
    cout << a << "\n";
  }
}