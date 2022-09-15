#include <iostream>
using namespace std;
int gear[5][9];
int input, cnt, num, dir;
int cur1R = 3, cur2L = 7, cur2R = 3, cur3L = 7, cur3R = 3, cur4L = 7;
int cur1T, cur2T, cur3T, cur4T;
int score = 0;

int main()
{
    cin.tie();
    ios::sync_with_stdio(0);
    for (int i = 1; i <= 4; i++)
    {
        cin >> input;
        for (int j = 8; j >= 1; j--)
        {
            gear[i][j] = input % 10;
            input /= 10;
        }
    }
    cin >> cnt;
    while (cnt--)
    {
        cin >> num >> dir;
        switch (num)
        {
        case 1:
            if (dir == 1)
            {
                if (gear[1][cur1R] != gear[2][cur2L])
                {
                    if (gear[2][cur2R] != gear[3][cur3L])
                    {
                        if (gear[3][cur3R] != gear[3][cur4L])
                        {
                            cur4L++;
                        }
                        cur3L--;
                        cur3R--;
                    }
                    cur2L++;
                    cur2R++;
                }
                cur1R--;
            }
            else
            {
                if (gear[1][cur1R] != gear[2][cur2L])
                {
                    if (gear[2][cur2R] != gear[3][cur3L])
                    {
                        if (gear[3][cur3R] != gear[4][cur4L])
                        {
                            cur4L--;
                        }
                        cur3L++;
                        cur3R++;
                    }
                    cur2L--;
                    cur2R--;
                }
                cur1R++;
            }
            break;
        case 2:
            if (dir == 1)
            {
                if (gear[2][cur2L] != gear[1][cur1R])
                {
                    cur1R++;
                }
                if (gear[2][cur2R] != gear[3][cur3L])
                {
                    if (gear[3][cur3R] != gear[4][cur4L])
                    {
                        cur4L--;
                    }
                    cur3L++;
                    cur3R++;
                }
                cur2L--;
                cur2R--;
            }
            else
            {
                if (gear[2][cur2L] != gear[1][cur1R])
                {
                    cur1R--;
                }
                if (gear[2][cur2R] != gear[3][cur3L])
                {
                    if (gear[3][cur3R] != gear[4][cur4L])
                    {
                        cur4L++;
                    }
                    cur3L--;
                    cur3R--;
                }
                cur2L++;
                cur2R++;
            }
            break;
        case 3:
            if (dir == 1)
            {
                if (gear[3][cur3L] != gear[2][cur2R])
                {
                    if (gear[2][cur2L] != gear[1][cur1R])
                    {
                        cur1R--;
                    }
                    cur2L++;
                    cur2R++;
                }
                if (gear[3][cur3R] != gear[4][cur4L])
                {
                    cur4L++;
                }
                cur3L--;
                cur3R--;
            }
            else
            {
                if (gear[3][cur3L] != gear[2][cur2R])
                {
                    if (gear[2][cur2L] != gear[1][cur1R])
                    {
                        cur1R++;
                    }
                    cur2L--;
                    cur2R--;
                }
                if (gear[3][cur3R] != gear[4][cur4L])
                {
                    cur4L--;
                }
                cur3L++;
                cur3R++;
            }
            break;
        case 4:
            if (dir == 1)
            {
                if (gear[4][cur4L] != gear[3][cur3R])
                {
                    if (gear[3][cur3L] != gear[2][cur2R])
                    {
                        if (gear[2][cur2L] != gear[1][cur1R])
                        {
                            cur1R++;
                        }
                        cur2L--;
                        cur2R--;
                    }
                    cur3L++;
                    cur3R++;
                }
                cur4L--;
            }
            else
            {
                if (gear[4][cur4L] != gear[3][cur3R])
                {
                    if (gear[3][cur3L] != gear[2][cur2R])
                    {
                        if (gear[2][cur2L] != gear[1][cur1R])
                        {
                            cur1R--;
                        }
                        cur2L++;
                        cur2R++;
                    }
                    cur3L--;
                    cur3R--;
                }
                cur4L++;
            }
            break;
        }
        if (cur1R <= 0)
            cur1R += 8;
        if (cur2L <= 0)
            cur2L += 8;
        if (cur2R <= 0)
            cur2R += 8;
        if (cur3L <= 0)
            cur3L += 8;
        if (cur3R <= 0)
            cur3R += 8;
        if (cur4L <= 0)
            cur4L += 8;
        if (cur1R > 8)
            cur1R -= 8;
        if (cur2L > 8)
            cur2L -= 8;
        if (cur2R > 8)
            cur2R -= 8;
        if (cur3L > 8)
            cur3L -= 8;
        if (cur3R > 8)
            cur3R -= 8;
        if (cur4L > 8)
            cur4L -= 8;
    }
    cur1T = cur1R - 2;
    cur2T = cur2R - 2;
    cur3T = cur3R - 2;
    cur4T = cur4L + 2;
    if (cur1T <= 0)
        cur1T += 8;
    if (cur2T <= 0)
        cur2T += 8;
    if (cur3T <= 0)
        cur3T += 8;
    if (cur4T <= 0)
        cur4T += 8;
    if (cur1T > 8)
        cur1T -= 8;
    if (cur2T > 8)
        cur2T -= 8;
    if (cur3T > 8)
        cur3T -= 8;
    if (cur4T > 8)
        cur4T -= 8;
    if (gear[1][cur1T] == 1)
        score += 1;
    if (gear[2][cur2T] == 1)
        score += 2;
    if (gear[3][cur3T] == 1)
        score += 4;
    if (gear[4][cur4T] == 1)
        score += 8;
    cout << score;
}