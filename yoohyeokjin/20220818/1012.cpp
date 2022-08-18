#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, x, y;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> m >> n >> k;
        int board[51][51];
        int vis[51][51];
        for(int i = 0; i < 51; i++){
            fill(board[i], board[i]+51, 0);
            fill(vis[i], vis[i]+51, 0);
        }
        for(int i = 0; i < k; i++){
            cin >> y >> x;
            board[x][y] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0 || vis[i][j]) continue;
                cnt++;
                queue<pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir <4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}