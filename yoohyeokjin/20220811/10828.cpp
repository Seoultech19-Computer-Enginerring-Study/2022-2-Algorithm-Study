#include <bits/stdc++.h>
using namespace std;

int n, arr[10001];
int pos = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i){
        string order = "";
        cin >> order;
        if(order == "pop"){
            if(pos == 0){
                cout << -1 << "\n";
            }
            else{
                cout << arr[--pos] << "\n";
            }
        }
        else if(order == "size"){
            cout << pos << "\n";
        }
        else if(order == "empty"){
            if(pos == 0){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(order == "top"){
            if(pos == 0){
                cout << -1 << "\n";
            }
            else{
                cout << arr[pos-1] << "\n";
            }
        }
        else{
            int x = 0;
            cin >> x;
            arr[pos++] = x;
        }
    }
}