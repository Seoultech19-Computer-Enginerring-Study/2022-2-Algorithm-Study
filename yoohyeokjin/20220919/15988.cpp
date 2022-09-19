#include <bits/stdc++.h>
using namespace std;

int T, n;
int DP[1000002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    DP[1] = 1; DP[2] = 2; DP[3] = 4;
    for(int i = 4; i < 1000001; i++){
        for(int j = 1; j <= 3; j++){
            DP[i] = (DP[i] + DP[i-j]) % 1000000009; // 오버플로우 가능성이 높다.
        }
    }
    for(int i = 0; i < T; i++){
        cin >> n;
        cout << DP[n] << "\n";
    }
}