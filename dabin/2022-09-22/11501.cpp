#include <iostream>
#include <string.h>
using namespace std;

int d[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(d, 0, sizeof(d));
        int n;
        cin >> n;
        for(int i=0; i<n; i++) cin >> d[i];
        int k=n-1;
        long long sum=0;
        for(int i=n-2; i>=0; i--) {
            if(d[k]>=d[i]) sum+=d[k]-d[i];
            else k=i;
        }
        cout << sum << '\n';
    }
}
/*
뒤부터 앞으로 훑음
뒤 값 >= 앞 값  동안 앞 값들 삼     뒷값-앞값을 더하여 sum 저장     뒷 값 유지
뒤 값 < 앞 값   앞 값 안 삼
*/