#include<iostream>
#include<queue>
using namespace std;
int N, num;
string x;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> Q;
    cin >> N;
    while(N--){
        cin >> x;
        if (x=="push"){
            cin >> num;
            Q.push(num);
        }
        else if (x=="pop") {
            if (Q.empty()) cout << -1 << "\n";
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (x=="size") cout << Q.size() << "\n";
        else if (x=="empty") cout << Q.empty() << "\n";
        else if (x=="front") {
            if (Q.empty()) cout << -1 << "\n";
            else cout << Q.front() << "\n";
        }
        else if (x=="back") {
            if (Q.empty()) cout << -1 << "\n";
            else cout << Q.back() << "\n";
        }
    }
}