#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
string board[1502];
int vis[1502][1502]; //물 전파 시간
int water[1502][1502];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int R, C;
int cnt = 0;
bool endflag = 0;
int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> board[i];
    while (1)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] == 'L')
                {
                    queue<pair<int, int>> Q;
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while (!Q.empty())
                    {
                        auto cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                                continue;
                            if (vis[nx][ny] || board[nx][ny] != '.')
                                continue;
                            if (board[nx][ny] == 'L')
                            {
                                cout << cnt;
                                return 0;
                            }
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            cout << vis[i][j] << ' ';
                        }
                        cout << " vis" << '\n';
                    }
                    cout << '\n';
                }
            }
        }
        for (int i = 0; i < R; i++)
            fill(vis[i], vis[i] + 1502, 0);
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] == '.' && water[i][j] == cnt)
                {
                    queue<pair<int, int>> Q;
                    water[i][j] = cnt;
                    Q.push({i, j});
                    while (!Q.empty())
                    {
                        auto cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                                continue;
                            if (water[nx][ny] || board[nx][ny] != 'X')
                                continue;
                            board[nx][ny] = '.';
                            water[nx][ny] = cnt + 1;
                        }
                    }
                }
            }
        }
        cnt++;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << water[i][j] << ' ';
            }
            cout << " water" << '\n';
        }
        cout << '\n';
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << " board" << cnt << '\n';
        }
        cout << '\n';
    }
}