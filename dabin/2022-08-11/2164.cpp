#include<iostream>
#include<queue>
using namespace std;
int N;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> Q;
    cin >> N;
    for(int i=1; i<=N; i++) Q.push(i);
    while(Q.size()!=1){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.back();
}