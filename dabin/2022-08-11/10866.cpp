#include<iostream>
#include<deque>
using namespace std;
int N, num;
string x;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    deque<int> DQ;
    cin >> N;
    while(N--) {
        cin >> x;
        if (x=="push_front") {
            cin >> num;
            DQ.push_front(num);
        }
        else if (x=="push_back") {
            cin >> num;
            DQ.push_back(num);
        }
        else if (x=="pop_front") {
            if (DQ.empty()) cout << -1 << "\n";
            else {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if (x=="pop_back") {
            if (DQ.empty()) cout << -1 << "\n";
            else {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if (x=="size") cout << DQ.size() << "\n";
        else if (x=="empty") cout << DQ.empty() << "\n";
        else if (x=="front") {
            if (DQ.empty()) cout << -1 << "\n";
            else cout << DQ.front() << "\n";
        }
        else if (x=="back") {
            if (DQ.empty()) cout << -1 << "\n";
            else cout << DQ.back() << "\n";
        }
    }
}