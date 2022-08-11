#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, arr[1000000] = {}, x, num[2000000] = {}, sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	for (int i = 1; i < n; i++) {
		if (num[x-arr[i]]) sum++;
		num[arr[i]] = 1;
	}
	cout << sum;
}