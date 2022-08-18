#include<bits/stdc++.h>
using namespace std;

int n;
string s[101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    queue<pair<int,int>> Q;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int cnt = 0, cntR = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]){
                if(s[i][j] == 'G') s[i][j] = 'R';
                continue;
            }
            cnt++;
            char curColor = s[i][j];
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir <4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || s[nx][ny] != curColor) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            if(s[i][j] == 'G') s[i][j] = 'R';
        }
    }
    for(int i = 0; i < 101; i++){
        fill(vis[i], vis[i]+101, 0);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]) continue;
            cntR++;
            char curColor = s[i][j];
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir <4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || s[nx][ny] != curColor) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << " " << cntR;
}