#include<bits/stdc++.h>
using namespace std;

int a,b,c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 1;
    cin >> a >> b >> c;
    for(int i = 0; i < b; i++){
        result = result * a % c;
    }
    cout << result;
}