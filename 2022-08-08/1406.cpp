#include <iostream>
#include <list>
using namespace std;

int main() {
    string sentence;
    char key, insert_key;
    int M;
    
    cin >> sentence >> M;
    list<char> N;
    for (int i:sentence) N.push_back(i);    //뒤쪽으로 원소 삽입
    auto cursur=N.end();                    //가장 마지막 원소 iterator 반환

    for (int i=0; i<M; i++){
        cin >> key;
        switch (key)
        {
        case 'L':
            if(cursur!=N.begin()) cursur--;
            break;
        case 'D':
            if(cursur!=N.end()) cursur++;
            break;
        case 'B':
            if(cursur!=N.begin()){
                cursur--;
                cursur = N.erase(cursur);    //삭제한 다음 원소 iterator 반환
            }
            break;
        case 'P':
            cin >> insert_key;
            N.insert(cursur, insert_key);   //삽입한 원소 iterator 반환
            break;
        default:
            break;
        }
    }
    for (char i:N) cout << i;
}