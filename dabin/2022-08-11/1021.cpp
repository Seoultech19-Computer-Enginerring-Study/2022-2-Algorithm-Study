#include<iostream>
#include<deque>
using namespace std;
int N, M, num, set, cnt = 0;

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(0);

    deque<int> DQ;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) DQ.push_back(i);
    while(M--){
        cin >> num;
        for(int i=0; i<DQ.size(); i++) if (DQ[i]==num) {
            set=i+1;
            break;
        }
        if (set <= (DQ.size()/2)+1) {
            while(num!=DQ.front()) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
                cnt++;
            }
        }
        else {
            while(num!=DQ.front()) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
                cnt++;
            }
        }
        DQ.pop_front();
    }
    cout << cnt;
}