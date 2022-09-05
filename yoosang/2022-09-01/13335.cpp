#include<bits/stdc++.h>
using namespace std;

int n, w, l;
int result;
int bridge[101];
queue<int> truck;

bool isEmpty(){
    for(int i=0;i<w;i++){
        if(bridge[i]) return false;
    }
    return true;
}

void go(){
    for(int i=w-1;i>0;i--){
        bridge[i] = bridge[i-1];
    }
    bridge[0] = 0;
}

int calculate() {
    int sum = 0;
    for(int i=0;i<w;i++){
        sum+=bridge[i];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>w>>l;
    int cur = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        truck.push(t);
    }

    do{
        int tmp = calculate();
        if(tmp<=l){ // 무게를 초과하지 않으면
            tmp-=bridge[w-1];   // 나갈 트럭의 무게를 제외
            go();               // 진행(내보내기만하고 트럭을 들여보내는 과정은 아래))
            // 아직 다리를 건너지 않은 트럭이 있고,
            //트럭을 다리위에 올려도(tmp에 더해도) 최대 하중보다 적으면 다리에 트럭을 올림
            if(!truck.empty()&&(tmp+truck.front()<=l)){
                bridge[0]=truck.front(); truck.pop();
            }
        }
        result++;
    }while(!isEmpty()); // 다리가 빌 때까지 반복
    cout<<result;
}