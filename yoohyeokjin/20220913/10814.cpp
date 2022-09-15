#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    pair<int,string> x[n];
    for (auto& s : x) cin >> s.first >> s.second;
    stable_sort(x, x+n, [&](pair<int,string> a, pair<int,string> b) { //람다 표현식 사용 [&:참조, =:복사](매개변수){실행할 코드}
        return a.first < b.first;
    });
    for (auto p : x) cout << p.first << ' ' << p.second << '\n';


}