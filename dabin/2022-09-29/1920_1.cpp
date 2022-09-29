#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, x;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    cin >> m;
    while(m--){
        cin >> x;
        cout << binary_search(a, a+n, x) << '\n';
    }
}