#include <iostream>
using namespace std;

int fac(int n){
    if(n==0) return 1;
    return n*fac(n-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << fac(n)/(fac(k)*fac(n-k));
}