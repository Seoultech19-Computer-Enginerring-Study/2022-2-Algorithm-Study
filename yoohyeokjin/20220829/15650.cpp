#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[10];
bool isused[10];

void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << "\n";
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!isused[i] || arr[k] < arr[k+1]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}