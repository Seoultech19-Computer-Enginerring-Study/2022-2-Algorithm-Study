#include <iostream>
using namespace std;
#define X first
#define Y second

pair<int, int> dot[100001], tmp[100001];

void merge(int st, int en) {
    int mid=(st+en)/2;
    int lidx=st;
    int ridx=mid;
    for (int i = st; i<en; i++) {
        if (ridx==en) tmp[i]=dot[lidx++];
        else if (lidx==mid) tmp[i]=dot[ridx++];
        else if (dot[lidx].X < dot[ridx].X) tmp[i]=dot[lidx++];
        else if (dot[lidx].X == dot[ridx].X) {
            if (dot[lidx].Y <= dot[ridx].Y) tmp[i]=dot[lidx++];
            else tmp[i]=dot[ridx++];
        }
        else tmp[i]=dot[ridx++];
    }
    for (int i = st; i<en; i++) dot[i]=tmp[i];
}

void merge_sort(int st, int en) {
    if (en==st+1) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        dot[i].X=x;
        dot[i].Y=y;
    }
    merge_sort(0, N);
    for(int i=0; i<N; i++) cout << dot[i].X << ' ' << dot[i].Y << '\n';
}