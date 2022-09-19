#include <bits/stdc++.h>
using namespace std;
int d[11];
// 관계식 유도
// d[1]=1, d[2]=2, d[3]=4, d[4]=7
// d[4]에서 4는
// 1+1+1+1 or 3+1 or 2+1+1 or 1+2+1 => d[4-1]
// 1+1+2 or 2+2                     => d[4-2]
// 1+3                              => d[4-3]
// => d[i]=d[i-1]+d[i-2]+d[i-3]
int main() {
  int t;
  cin >> t;
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;
  for (int i = 4; i <= 11; i++) {
    d[i] = d[i - 1] + d[i - 2] + d[i - 3];
  }
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << d[n] << "\n";
  }
}