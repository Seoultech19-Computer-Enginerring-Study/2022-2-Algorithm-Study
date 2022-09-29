#include <iostream>
#include <algorithm>

using namespace std;

int a[500001];
int n;

int lower_idx(int x, int len){
    int st=0;
    int en=len;
    while(st<en){
        int mid=(st+en)/2;
        if(a[mid]>=x) en=mid;
        else st=mid+1;
    }
    return st;
}

int upper_idx(int x, int len){
    int st=0;
    int en=len;
    while(st<en){
        int mid=(st+en)/2;
        if(a[mid]>x) en=mid;
        else st=mid+1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, x;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    cin >> m;
    while(m--){
        cin >> x;
        cout << upper_idx(x, n)-lower_idx(x, n) << ' ';
    }
}