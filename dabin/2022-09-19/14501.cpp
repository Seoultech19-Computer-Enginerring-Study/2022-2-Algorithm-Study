#include <iostream>
#include <algorithm>
using namespace std;

int d[16], t[16], p[16];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];
    for (int i = n; i >= 1; i--)
    {
        if (i + t[i] <= n + 1)
            d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
        else
            d[i] = d[i + 1];
    }
    cout << *max_element(d, d + n + 1);
}