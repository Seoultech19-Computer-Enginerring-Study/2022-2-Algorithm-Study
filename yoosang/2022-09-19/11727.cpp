#include<bits/stdc++.h>

using namespace std;
int n;
int arr[1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    arr[1] = 1;
    arr[2] = 3;
    for(int i=3;i<=1000;i++){
        arr[i] = arr[i-1] % 10007 + 2 * arr[i-2] % 10007;
    }
    cout<<arr[n]%10007;
}