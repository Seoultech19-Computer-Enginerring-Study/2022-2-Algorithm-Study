#include<bits/stdc++.h>

using namespace std;

int arr[1000001];
vector<int> sequence;
int n;

void binary_search(int num) {
  int s = 0, e = sequence.size() - 1;
  int mid;
  int result = 1000000007;
  while (s <= e) {
    mid = (s + e) / 2;
    if (sequence[mid] >= num) {
      if (result > mid) result = mid;
      e = mid - 1;
    } else
      s = mid + 1;
  }

  sequence[result] = num;
}

void find_lis() {
  sequence.push_back(arr[0]);
  for (int i = 1; i < n; i++) {
    if (sequence.back() < arr[i]) {
      sequence.push_back(arr[i]);
    } else {
      binary_search(arr[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  find_lis();

  cout << sequence.size();

  return 0;
}