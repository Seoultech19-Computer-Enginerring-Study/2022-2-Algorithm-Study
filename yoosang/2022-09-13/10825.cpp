#include<bits/stdc++.h>

using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<tuple<int, int, int, string>> v;

    for(int i=0;i<n;i++){
        int k, e, m;
        string name;
        cin>>name>>k>>e>>m;
        v.push_back({-k, e, -m, name});
    }
    sort(v.begin(), v.end());

    for(auto &a: v){
        cout<<get<3>(a)<<'\n';
    }
}