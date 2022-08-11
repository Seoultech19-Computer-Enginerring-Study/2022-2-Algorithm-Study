#include <bits/stdc++.h>
using namespace std;

string check(string a){
    stack<char> s;
    for(char x : a){
        if(x == '(' || x == '['){
            s.push(x);
        }
        else if(x == ')'){
            if(s.empty() || s.top() != '('){
                return "no";
            }
            else{
                s.pop();
            }
        }
        else if(x == ']'){
            if(s.empty() || s.top() != '['){
                return "no";
            }
            else{
                s.pop();
            }
        }
    }
    if(!s.empty()) return "no";
    else return "yes";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(true){
        getline(cin, str);
        if(str == ".") break;
        cout << check(str) << "\n";
    }
}