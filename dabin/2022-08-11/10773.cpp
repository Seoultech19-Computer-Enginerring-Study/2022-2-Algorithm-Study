#include<iostream>
#include<stack>

using namespace std;

int K, sum, N;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    stack<int> S;
    cin >> K;
    while(K--){
        cin >> N;
        if(N==0) S.pop();
        else S.push(N);
    }
    while(!S.empty()){
        sum+=S.top();
        S.pop();
    }
    cout << sum;
}