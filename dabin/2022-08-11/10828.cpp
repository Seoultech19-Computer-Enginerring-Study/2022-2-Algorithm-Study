#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, x;
    string str;
    stack<int> S;
    cin >> N;
    while(N--){
        cin >> str;
        if (str=="push"){
            cin >> x;
            S.push(x);
        }
        else if (str=="pop"){
            if (S.empty()) cout << -1 << "\n";
            else {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (str=="size"){
            cout << S.size() << "\n";
        }
        else if (str=="empty"){
            if (S.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (str=="top"){
            if(S.empty()) cout << -1 << "\n";
            else cout << S.top() << "\n";
        }
    }
}