#include <iostream>
#include <vector>

using namespace std;

int queen[10000];
int n;
int ans;

int cnt = 0;

bool isAvailable(int row, int col) {
  for (int i = 0; i < row; i++) {
    if (queen[i] == col || abs(queen[i] - col) == row - i) return false;
  }
  return true;
}
void dfs(int row) {
  if (row == n) {
    cnt++;
  }

  for (int i = 0; i < n; i++) {
    if (isAvailable(row, i)) {
      queen[row] = i;
      dfs(row + 1);
    }
  }
}

int main() {
  cin >> n;
  dfs(0);
  cout << cnt;
}