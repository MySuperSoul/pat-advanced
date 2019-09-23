#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

typedef long long ll;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

void OutputForVector(vector<int>& ans){
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
}

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 0; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

#define maxn 105

typedef struct node{
    int index;
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

vector<node_ptr> node_vec;

int n;

vector<int> index_vec;
void InOrder(node_ptr root){
    if (root == nullptr) return;
    InOrder(root->left);
    index_vec.push_back(root->index);
    InOrder(root->right);
}

vector<int> level;
void LevelOrder(node_ptr root){
    queue<node_ptr> q;
    q.push(root);

    while(!q.empty()){
        node_ptr n = q.front(); q.pop();
        level.push_back(n->value);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
}

int main()
{
    cin >> n;
    node_vec.resize(n);

    for (int i = 0; i < n; i++) node_vec[i] = new Node;

    for (int i = 0; i < n; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        node_ptr n = node_vec[i];
        n->index = i;
        if (v1 != -1) n->left = node_vec[v1];
        if (v2 != -1) n->right = node_vec[v2];
    }

    vector<int> ans;
    ans.resize(n);

    for (int i = 0; i < n; i++) scanf("%d", &ans[i]);
    sort(ans.begin(), ans.end());

    node_ptr root = node_vec[0];
    InOrder(root);

    for (int i = 0; i < index_vec.size(); i++){
        node_vec[index_vec[i]]->value = ans[i];
    }

    LevelOrder(root);
    OutputForVector(level);

    return 0;
}
