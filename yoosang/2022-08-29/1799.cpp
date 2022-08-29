#include <bits/stdc++.h>

using namespace std;
int n;
int board[11][11];
int bishop[11][11];
int result = 0;
int cnt = 0;
bool isAvailable(int x, int y) { 
    if(board[x][y]==0) return false;
    int nx = x, ny = y;
    while(nx>=0&&ny>=0) {
        
    }
}

void dfs(int x, int y) {
  int nx = (x + 1) % n;
  int ny = y + (x + 1) / n;

  if (isAvailable(nx, ny)) {
    bishop[nx][ny] = 1;
    cnt++;
    dfs(nx, ny);
    cnt--;
    bishop[nx][ny] = 0;
  }
  dfs(nx, ny);

  if (x == n - 1 && y == n - 1) {
    result = max(result, cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  dfs(0, 0);
  cout << result;
}