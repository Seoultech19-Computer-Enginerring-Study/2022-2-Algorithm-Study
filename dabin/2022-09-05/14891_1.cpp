#include <iostream>
#include <algorithm>
using namespace std;

string gear[4];

void func(int num, int dir)
{
    int dirs[4] = {};
    dirs[num] = dir;
    int r_num = num;
    while (r_num > 0 && gear[r_num][6] != gear[r_num - 1][2]) //왼쪽
    {
        dirs[r_num - 1] = -dirs[r_num];
        r_num--;
    }
    r_num = num;
    while (r_num < 3 && gear[r_num][2] != gear[r_num + 1][6]) //오른쪽
    {
        dirs[r_num + 1] = -dirs[r_num];
        r_num++;
    }
    for (int i = 0; i < 4; i++)
    {
        if (dirs[i] == -1)
            rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
        else if (dirs[i] == 1)
            rotate(gear[i].begin(), gear[i].end() - 1, gear[i].end());
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++)
        cin >> gear[i];
    int k;
    cin >> k;
    while (k--)
    {
        int num, dir;
        cin >> num >> dir;
        func(num - 1, dir);
    }
    int score = 0;
    for (int i = 0; i < 4; i++)
        if (gear[i][0] == '1')
            score += (1 << i);
    cout << score;
}