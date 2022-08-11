#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, k, l;
// int snake[101][101];
deque<pair<int, int>> snake;
int board[101][101];
int apple[101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> k;
  // 사과 위치 표시
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    apple[x][y] = 1;
  }

  cin >> l;
  vector<pair<int, char>> v;

  for(int i=0;i<l;i++){
    int s;
    char c;
    cin>>s>>c;
    v.push_back({s, c});
  }

  int sec = 0;
  int dir = 0;
  snake.push_back({1, 1});
  int x = 1, y = 1;
  while(true) {
    // 다음 위치 탐색
    x += dx[dir];
    y += dy[dir];

    // 종료 조건(벽)확인
    if(x<=0||x>n||y<=0||y>n){
        cout<<sec;
        break;
    }
    // 자기 몸에 부딪히는지 확인
    if (board[x][y] == 1) {
      cout << sec;
      break;
    }
    // 사과 확인
    if(!apple[x][y]) {    // 사과가 없으면 꼬리를 지움
        auto a = snake.back();
        board[a.first][a.second] = 0;
        snake.pop_back();
    }
    
    // 머리 추가
    snake.push_front({x, y});
    board[x][y] = 1;

    // 방향 전환
    for(auto a : v) {
        if(sec == a.first){
            if(a.second == 'L'){
                dir+=4;
                dir--;
                dir%=4;
            }
            if(a.second == 'D'){
                dir++;
                dir%=4;
            }
            break;
        }
    }
    sec++;
  }
}