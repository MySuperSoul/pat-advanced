#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

#define maxn 15

typedef struct node{
    int value = -1;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

vector<node_ptr> node_vec;

int visit[maxn];

int root;
int n;
void FindRoot(){
    for (int i = 0; i < n; i++){
        if (visit[i] == 0) {
            root = i;
            break;
        }
    }
}

vector<int> In;
void InOrder(node_ptr root){
    if (root == nullptr) return;

    InOrder(root->right);
    In.push_back(root->value);
    InOrder(root->left);
}

vector<int> level;
void LevelOrder(node_ptr root){
    queue<node_ptr> q;
    q.push(root);

    while(!q.empty()){
        node_ptr n = q.front(); q.pop();
        level.push_back(n->value);
        if (n->right) q.push(n->right);
        if (n->left) q.push(n->left);
    }
}

void Output(vector<int>& ans){
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
}

int main()
{
    cin >> n;

    string s1, s2;
    node_vec.resize(n);

    for (int i = 0; i < n; i++) node_vec[i] = new Node;
    for (int i = 0; i < n; i++){
        cin >> s1 >> s2;
        node_vec[i]->value = i;

        if (s1 != "-"){
            node_vec[i]->left = node_vec[stoi(s1)];
            visit[stoi(s1)] = 1;
        }

        if (s2 != "-"){
            node_vec[i]->right = node_vec[stoi(s2)];
            visit[stoi(s2)] = 1;
        }
    }

    FindRoot();

    node_ptr r = node_vec[root];
    LevelOrder(r);
    InOrder(r);

    Output(level);
    cout << endl;
    Output(In);

    return 0;
}
