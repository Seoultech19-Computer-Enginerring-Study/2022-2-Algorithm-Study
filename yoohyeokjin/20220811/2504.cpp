// 문제에서 곱하기를 분배하고 전위로 먼저 계산한다고 생각해야 풀린다.
#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> s;
int sum = 0;
int num = 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            num *= 2;
            s.push(str[i]);
        }
        else if(str[i] == '['){
            num *= 3;
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '('){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(') sum += num;
            s.pop();
            num /= 2;
        }
        else{
            if(s.empty() || s.top() != '['){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') sum += num;
            s.pop();
            num /= 3;
        }
    }
    if(s.empty()) cout << sum;
    else cout << 0;
}

