#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, array[10005];
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> array[i];
    }

    for(int i = 0; i < a; i++){
        if(array[i] < b){
            cout << array[i] << " ";
        }
    }
    return 0;
}