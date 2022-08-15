#include <bits/stdc++.h>
using namespace std;

bool vis[1001];
vector<short> edge[1001];
queue<int> q;
int n, m;
int u, v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    edge[v].push_back(u);
    edge[u].push_back(v);
  }
  int result = 0;
  for (int i = 1; i <= n; i++) {
    // 이미 지나간 정점이면
    if (vis[i]) continue;
    result++;
    q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      vis[cur] = true;
      for (int j = 0; j < v[cur].size(); j++) {
        // 이미 지나간 정점이면
        if (vis[edge[cur][j]]) continue;
        q.push(edge[cur][j]);
      }
    }
  }
  cout << result;
}