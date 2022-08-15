#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define X first
#define Y second
string board[102];
int vis[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (vis[nx][ny] > 0 || board[nx][ny] != '1')
                continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << vis[N - 1][M - 1];
}