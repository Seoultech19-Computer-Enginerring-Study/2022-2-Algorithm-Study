#include <bits/stdc++.h>
using namespace std;

int n, arr[10001];
int head = 0, tail = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i){
        string order = "";
        cin >> order;
        if(order == "pop"){
            if(tail == head){
                cout << -1 << "\n";
            }
            else{
                cout << arr[head++] << "\n";
            }
        }
        else if(order == "size"){
            cout << tail - head << "\n";
        }
        else if(order == "empty"){
            if(tail == head){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(order == "front"){
            if(tail == head){
                cout << -1 << "\n";
            }
            else{
                cout << arr[head] << "\n";
            }
        }
        else if(order == "back"){
            if(tail == head){
                cout << -1 << "\n";
            }
            else{
                cout << arr[tail-1] << "\n";
            }
        }
        else{
            int x = 0;
            cin >> x;
            arr[tail++] = x;
        }
    }
}