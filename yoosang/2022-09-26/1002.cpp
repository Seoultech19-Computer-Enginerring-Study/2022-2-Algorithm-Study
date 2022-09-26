#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  float x1, y1, r1, x2, y2, r2, r;
  for (int i = 0; i < T; i++) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (r > r2 + r1 || r1 + r < r2 || r2 + r < r1) {
      cout << 0 << "\n";
    } else if (r == 0 && r1 == r2) {
      cout << "-1"
           << "\n";
    } else if (r == r2 + r1 || r + r1 == r2 || r + r2 == r1) {
      cout << 1 << "\n";
    }

    else {
      cout << 2 << "\n";
    }
  }

  return 0;
}