#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<bool> state(n+1, true);
    state[1]=false;
    for(int i=2; i*i<=n; i++) {
        if(!state[i]) continue;
        for(int j=i*i; j<=n; j+=i)
            state[j]=false;
    }
    for(int i=m; i<=n; i++){
        if(state[i]) cout << i << '\n';
    }
}