#include<bits/stdc++.h>
using namespace std;

int n,k;
int dis[200001];
pair<int,int> dx[3] = {{1,-1}, {1,1}, {2,0}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dis,dis + 200000, -1);
    queue<int> Q;
    dis[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        if(Q.front() == k) break;
        int cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 3; dir++){
            int ndis = cur * dx[dir].first + dx[dir].second;
            if(ndis < 0 || ndis > 200000) continue;
            if(dis[ndis] >= 0) continue;
            dis[ndis] = dis[cur] + 1;
            Q.push(ndis);
        }
    }
    cout << dis[k];
}