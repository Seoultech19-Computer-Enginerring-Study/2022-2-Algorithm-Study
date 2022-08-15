#include <iostream>
#include <list>
using namespace std;

int main() {
    string sentence;
    char key, insert_key;
    int M;
    
    cin >> sentence >> M;
    list<char> N;
    for (int i:sentence) N.push_back(i);    //�������� ���� ����
    auto cursur=N.end();                    //���� ������ ���� iterator ��ȯ

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
                cursur = N.erase(cursur);    //������ ���� ���� iterator ��ȯ
            }
            break;
        case 'P':
            cin >> insert_key;
            N.insert(cursur, insert_key);   //������ ���� iterator ��ȯ
            break;
        default:
            break;
        }
    }
    for (char i:N) cout << i;
}