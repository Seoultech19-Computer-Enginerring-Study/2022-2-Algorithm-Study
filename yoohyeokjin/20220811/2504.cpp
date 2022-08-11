#include <bits/stdc++.h>
using namespace std;

string str;
int func(){
    int result = 0;
    stack<char> s;
    for(auto c : str){
        if(c == '(' || c == '['){
            s.push(c);
        }
        else if(c == ')'){
            if(s.empty() || s.top() != '(') return 0;
            else{
                s.pop();
                if(!s.empty() && (s.top() == '(' || s.top() == '[')){
                    s.push('2');
                }
                else if(!s.empty() && (s.top() == '2' || s.top() == '3')){
                    result += s.top();
                    result *= 2;
                }
                else{
                    result += 2;
                }
            }
        }
        else if(c == ']'){
            if(s.empty() || s.top() != '[') return 0;
            else{
                s.pop();
                if(!s.empty() && (s.top() == '[' || s.top() == '(')){
                    s.push('3');
                }
                else if(!s.empty() && (s.top() == '2' || s.top() == '3')){
                    result += s.top();
                    result *= 3;
                }
                else{
                    result += 3;
                }
            }
        }
    }
    if(!s.empty()) return 0;
    else return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    cout << func();
}

