#include<iostream>
#include<stack>

using namespace std;

int n, num, cnt=1;
string ans;

int main(){
    stack<int> s;
    cin >> n;
    while(n--){
        cin >> num;
        while(cnt<=num){
            s.push(cnt++);
            ans += "+\n";
        }
        if(s.top()!=num){
            cout << "NO";
            return 0;
        }
        s.pop();
        ans += "-\n";
    }
    cout << ans;
}