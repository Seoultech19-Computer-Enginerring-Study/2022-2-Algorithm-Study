#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int arr1[10][10];
int arr2[10][10];

bool OOB(int a, int b){
    return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y) || arr2[x][y] == 6) return;
        if(arr2[x][y] != 0) continue;
        arr2[x][y] = 7;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> cctv;
    int result = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr1[i][j];
            if(arr1[i][j] != 0 && arr1[i][j] != 6) cctv.push_back({i,j});
            if(arr1[i][j] == 0) result++;
        }
    }
    for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr2[i][j] = arr1[i][j];
            }
        }
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++){
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if(arr1[x][y] == 1){
                upd(x,y,dir);
            }
            else if(arr1[x][y] == 2){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }
            else if(arr1[x][y] == 3){
                upd(x,y,dir);
                upd(x,y,dir+1);
            }
            else if(arr1[x][y] == 4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            else if(arr1[x][y] == 5){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }
            int val = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    val += (arr2[i][j] == 0);
                }
            }
            result = min(result, val);
    }
    cout << result;
}