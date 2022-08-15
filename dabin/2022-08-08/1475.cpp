#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[10]={}, N, num;
    cin >> N;
    while(N){
        arr[N%10]++;
        N/=10;
    }
    arr[6]=(arr[9]+1)/2;
    arr[9]=0;
    cout << *max_element(arr,arr+10);
}