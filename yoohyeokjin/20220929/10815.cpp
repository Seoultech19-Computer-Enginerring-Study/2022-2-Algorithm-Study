#include <bits/stdc++.h>
using namespace std;

vector<int> vn;
vector<int> vm;

int binarysearch(int target, int n){
    int st = 0;
    int en = n - 1;
    while(st <= en){
        int mid = (st + en) / 2;
        if(vn[mid] < target){
            st =  mid + 1;
        }
        else if(vn[mid] > target){
            en = mid - 1;
        }
        else return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        vn.push_back(tmp);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        vm.push_back(tmp);
    }
    sort(vn.begin(),vn.end());
    for(int i = 0; i < vm.size(); i++){
        cout << binarysearch(vm[i],vn.size()) << " ";
    }
}