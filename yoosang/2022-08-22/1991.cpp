#include<bits/stdc++.h>
using namespace std;

int n;
char tree[26][2];
queue<char> inorder;
queue<char> postorder;
queue<char> preorder;
void dfs(char c) {
    preorder.push(c);
    if (tree[c-'A'][0] != '.') dfs(tree[c-'A'][0]);
    inorder.push(c);
    if (tree[c - 'A'][1] != '.') dfs(tree[c - 'A'][1]);
    postorder.push(c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        char c, a, b;
        cin>>c>>a>>b;
        tree[c - 'A'][0] = a;
        tree[c - 'A'][1] = b;
    }
    dfs('A');

    while (!preorder.empty()) {
      cout << preorder.front();
      preorder.pop();
    }
    cout << '\n';
    
    while (!inorder.empty()) {
      cout << inorder.front();
      inorder.pop();
    }
    cout << '\n';

    while (!postorder.empty()) {
      cout << postorder.front();
      postorder.pop();
    }
    cout << '\n';
}