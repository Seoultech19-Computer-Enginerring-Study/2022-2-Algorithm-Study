#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, v2, tmp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    for(int i=0; i<a; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i<b; i++) {
        int y;
        cin >> y;
        v2.push_back(y);
    }
    sort(v.begin(), v.end());
    //sort(v2.begin(), v2.end());
    for(int i=0; i<a; i++){
        cout << v[i] << ' ';
    }
    // for(int i=0; i<a; i++){
    //     if(binary_search(v2.begin(), v2.end(), v1[i])) {
    //         tmp.push_back(v1[i]);
    //     }
    // }
    // cout << tmp.size() << '\n';
    // if(!tmp.size()){
    //     for(int i=0; i<tmp.size(); i++){
    //         cout << tmp[i] << ' ';
    //     }
    // }
}