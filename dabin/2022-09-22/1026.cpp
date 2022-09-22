#include <iostream>
#include <algorithm>

using namespace std;

int A[55], B[55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) cin >> B[i];
    sort(A, A+n);
    sort(B, B+n, greater<>());
    int sum=0;
    for(int i=0; i<n; i++) sum += A[i]*B[i];
    cout << sum;
}