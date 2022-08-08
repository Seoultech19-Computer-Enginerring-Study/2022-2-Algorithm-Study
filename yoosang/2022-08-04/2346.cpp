#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  deque<pair<int, int>> d;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    d.push_back({i + 1, num});
  }

  while(!d.empty()){
    auto a = d.front();
    d.pop_front();
    cout << a.first << ' ';
    if (a.second > 0) {
      int cnt = a.second;
      while (--cnt) {
        d.push_back(d.front());
        d.pop_front();
      }
    } else {
      int cnt = 1-a.second;
      while (--cnt) {
        d.push_front(d.back());
        d.pop_back();
      }
    }
  }
}