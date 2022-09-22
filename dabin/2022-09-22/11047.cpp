#include<iostream>
using namespace std;

int n, k, a[11], cnt=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=n; i>0; i--){
        cnt += k / a[i];
        k %= a[i];
    }
    cout << cnt;
}