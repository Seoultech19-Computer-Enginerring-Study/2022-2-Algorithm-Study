#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> edge[11];
int population[11];
int sum;
int vis[11];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> population[i];
    sum += population[i];
  }

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    while (a--) {
      int v;
      cin >> v;
      edge[i].push_back(v);
    }
  }
  int result = 2147483647;

  for (int k = 1; k < n; k++) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
      arr.push_back(i);
    }
    // 0과1을 저장 할 벡터 생성
    vector<int> ind;

    // k개의 1 추가
    for (int i = 0; i < k; i++) {
      ind.push_back(1);
    }

    // 2개(6개-2개)의 0 추가
    for (int i = 0; i < arr.size() - k; i++) {
      ind.push_back(0);
    }

    // 정렬
    sort(ind.begin(), ind.end());
    //순열
    do {
      // 출력
      // for (int i = 0; i < ind.size(); i++) {
      //   if (ind[i] == 1) {
      //     printf("%d ", arr[i]);
      //   }
      // }
      // printf("\n");

      int arr[11] = {0};
      for (auto a : ind) {
        arr[a] = 1;
      }
      memset(vis, 0, sizeof(vis));
      bfs(ind[0]);
      bool flag = true;
      for (int i = 0; i < n; i++) {
        // 연결 안되어있으면
        if (arr[i] == 1 && vis[arr[i]])
          continue;
        else
          flag = false;
      }
      if (flag) break;
      memset(vis, 0, sizeof(vis));
      // 두번째 bfs 시작
      for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
          bfs(arr[i]);
          
          break;
        }
      }
      flag = true;
      for (int i = 0; i < n; i++) {
        // 연결 안되어있으면
        if (arr[i] == 0 && vis[arr[i]])
          continue;
        else
          flag = false;
      }
      if (flag) break;
    } while (next_permutation(ind.begin(), ind.end()));
  }
}