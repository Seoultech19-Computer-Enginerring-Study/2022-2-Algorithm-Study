#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> V;
list<pair<int, int>> L;
char arr[12][6];

void changeArr(){
    int cnt = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 11; j >= 0; j--){
            if(arr[j][i] == '.') {
                cnt++;
            }
            else{
                if(cnt == 0) continue;
                arr[j+cnt][i] = arr[j][i];
                arr[j][i] = '.';
            }
        }
        cnt = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    bool visit[12][6];
    vector<pair<int, int>>::iterator it;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }

    do{
        changeArr();
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(arr[i][j] != '.') L.push_back({i,j});
                visit[i][j] = false;
            }
        }
        int breakPoint = L.size();
        int notChain = L.size();
        while(!L.empty()){
            int cntChain = 1;
            queue<pair<int, int>> funcQ;
            funcQ.push(L.front());
            V.push_back(L.front());
            visit[L.front().X][L.front().Y] = true;
            while(!funcQ.empty()){
                pair<int,int> cur = funcQ.front(); funcQ.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                    if(visit[nx][ny] || arr[nx][ny] == '.' || arr[nx][ny] != arr[L.front().X][L.front().Y]) continue;
                    funcQ.push({nx,ny});
                    V.push_back({nx,ny});
                    visit[nx][ny] = true;
                    cntChain++;
                }
            }
            if(cntChain >= 4){
                for(it = V.begin(); it != V.end(); it++){
                    L.remove(*it);
                    arr[it->X][it->Y] = '.';
                }
                V.clear();
                notChain -= cntChain;
            }
            else{
                V.clear();
                L.pop_front();
            }
        }
        if(breakPoint == notChain) break;
        cnt++;
    } while(1);

    cout << cnt;
}

