#include <iostream>
#include <queue>
using namespace std;
int board[1002][1002];
bool visit[1002];
int N, M, V;

void DFS(int V)
{
    visit[V] = 1;
    cout << V << " ";
    for (int i = 1; i <= N; i++)
    {
        if (board[V][i] && !visit[i])
        {
            DFS(i);
        }
    }
}

void BFS(int V)
{
    queue<int> Q;
    Q.push(V);
    visit[V] = 1;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        cout << cur << " ";
        for (int i = 1; i <= N; i++)
        {
            if (board[cur][i] && !visit[i])
            {
                visit[i] = 1;
                Q.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> V;
    int n1, n2;
    for (int i = 0; i < M; i++)
    {
        cin >> n1 >> n2;
        board[n1][n2] = board[n2][n1] = 1;
    }
    DFS(V);
    for (int i = 1; i <= N; i++)
        visit[i] = 0;
    cout << '\n';
    BFS(V);
}