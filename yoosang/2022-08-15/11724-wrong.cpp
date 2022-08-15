#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];
bool vis[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin>>n>>m;
    vector<pair<int, int>> v;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    queue<int> q;
    int result = 0;
    for(int i=1;i<=n;i++) {
        // 이미 지나간 정점이면
        if(vis[i]) continue;
        result++;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            vis[cur]=true;
            for(int j=1;j<=n;j++) {
              // 이미 지나간 정점이면
              if (vis[j]) continue;
              if (arr[cur][j]) q.push(j);
            }
        }
    }
    cout<<result;
}