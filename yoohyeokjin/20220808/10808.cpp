#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    int array[26] = {};
    cin >> a;
    for(int i=0; i < a.length(); i++){
        array[a[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        cout << array[i] << " ";
    }
    return 0;
}