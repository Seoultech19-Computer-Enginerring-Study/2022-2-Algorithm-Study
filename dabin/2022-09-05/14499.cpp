#include <iostream>
using namespace std;

int map[21][21];
int dir, N, M, x, y;
int t = 0, b = 0, e = 0, w = 0, s = 0, n = 0;
int temp;

void zerocheck()
{
    if (map[x][y] == 0)
        map[x][y] = b;
    else
    {
        b = map[x][y];
        map[x][y] = 0;
    }
    // cout << n << w << t << e << s << b << '\n';
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << map[i][j];
    //     }
    //     cout << '\n';
    // }
}

void func(int k)
{
    switch (k)
    {
    case 1:
        if (x + 1 >= M)
            break;
        x++;
        temp = t;
        t = w;
        w = b;
        b = e;
        e = temp;
        cout << t << '\n';
        zerocheck();
        break;
    case 2:
        if (x - 1 < 0)
            break;
        x--;
        temp = t;
        t = e;
        e = b;
        b = w;
        w = temp;
        cout << t << '\n';
        zerocheck();
        break;
    case 3:
        if (y - 1 < 0)
            break;
        y--;
        temp = t;
        t = s;
        s = b;
        b = n;
        n = temp;
        cout << t << '\n';
        zerocheck();
        break;
    case 4:
        if (y + 1 >= N)
            break;
        y++;
        temp = t;
        t = n;
        n = b;
        b = s;
        s = temp;
        cout << t << '\n';
        zerocheck();
        break;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int k;
    cin >> N >> M >> x >> y >> k;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            map[i][j] = num;
        }
    }
    while (k--)
    {
        cin >> dir;
        func(dir);
    }
}