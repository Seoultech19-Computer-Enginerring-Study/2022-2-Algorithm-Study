#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    int sum = 0, temp = 0;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++){
        temp += v[i];
        sum += temp;
    }
    cout << sum;
}