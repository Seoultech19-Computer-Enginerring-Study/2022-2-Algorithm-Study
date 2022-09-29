#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n, m;

bool binarySearch(int num) {
    int st = 0, end = n-1;
    while(st<=end){
      int mid = (st + end) / 2;
      if (a[mid] == num) return true;
      if (a[mid] < num)
        st = mid + 1;
      else if (a[mid] > num)
        end = mid - 1;
    }
    return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);

  cin >> m;

  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    if (binarySearch(num))
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
}