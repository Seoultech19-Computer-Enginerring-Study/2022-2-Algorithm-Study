#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, r, result=0;
    int arr[2][6] = {0,};

    cin >> s >> r;

    for(int i = 0; i < s; i++){
        int a,b;
        cin >> a >> b;
        arr[a][b-1]++;
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
                result += arr[i][j] / r;
                if (arr[i][j] % r) result++;
        }
    }
    cout << result;
    return 0;
}
