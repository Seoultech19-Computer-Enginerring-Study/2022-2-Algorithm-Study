#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int num = 0;
    cin >> n >> k;
    vector<bool> v(n+1, true);
    for(int i = 2; i <= n; i++){
        if(v[i]){
            v[i] = false;
            num++;
            if(num == k){
                cout << i;
                return 0;
            }
        } 
        else continue;
        for(int j = 2; i * j <= n; j++){
            if(!v[i * j]) continue;
            v[i * j] =false;
            num++;
            if(num == k){
                cout << i * j;
                return 0;
            }
        }
    }
}
