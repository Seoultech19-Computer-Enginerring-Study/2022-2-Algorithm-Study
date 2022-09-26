#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a,b,A,B;
    cin >> A >> B;
    if(A == B){
        cout << 0;
        return 0;
    }
    else if(A > B){
        a = A;
        b = B;
    }
    else{
        a = B;
        b = A;
    }
    cout << a - b - 1 << "\n";
    for(long long i = b+1; i < a; i++){
        cout << i << " ";
    }
}
