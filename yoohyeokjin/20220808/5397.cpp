#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        list<char> L = {};
        string x;
        auto cursor = L.begin();
        cin >> x;
        for(auto c : x){
            if(c == '<'){
                if (cursor != L.begin()) cursor--;
            }
            else if(c == '>'){
                if(cursor != L.end()) cursor++;
            }
            else if(c == '-'){
                if (cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else{
                L.insert(cursor, c);
            }
        }
        for (auto c: L) cout << c;
        cout << "\n";
    }
}