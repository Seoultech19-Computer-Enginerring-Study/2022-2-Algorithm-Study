#include <bits/stdc++.h>
using namespace std;
int n, k;

int bowl[102];
int m[102][102];

bool isAvailable1() {
  int h = 0, w = 0;
  int floor = 0;
  // 높이 결정
  while (m[h][0]) {
    h++;
  }
  if (h == 1) return true;
  while (m[h - 1][w]) {
    w++;
  }
  while (m[0][floor]) {
    floor++;
  }
  if (floor - w >= h) return true;
  return false;
}

void moveBowl1() {
  while (isAvailable1()) {
    int h = 0, w = 0;
    while (m[h][0]) {
      h++;
    }
    while (m[h - 1][w]) {
      w++;
    }
    int temp[102][102];
    for (int i = 0; i < n - h; i++) {
      temp[0][i] = m[0][i + w];
    }
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        temp[i + w][j] = m[j][i];
      }
    }
    memset(m, 0, sizeof(m));
    for (int i = 0; i < 102; i++) {
      for (int j = 0; j < 102; j++) {
        m[i][j] = temp[i][j];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> bowl[i];
  }
  for (int i = 0; i < n; i++) {
    m[0][i] = i + 1;
  }
  moveBowl1();
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      cout << m[i][j];
    }
    cout << '\n';
  }
}