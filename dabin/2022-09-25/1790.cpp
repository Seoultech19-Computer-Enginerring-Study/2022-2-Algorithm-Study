#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int len = 1, exp = 1;
    while (k > 9LL * len * exp) {
        k -= 9LL * len * exp;
        exp *= 10;
        len++;
    }
    int num = exp + (k - 1) / len;
    if (num > n) cout << -1;
    else cout << to_string(num)[(k - 1) % len];
}

/*
        num     len     exp     길이
1~9     9       1       1       9*1*1
10~99   90      2       10      9*10*2
100~999 900     3       100     9*100*3

9*len*exp

23  14
10 11 12 13 14 15 16

24  15
10 11 12 13 14 15 16 17
*/