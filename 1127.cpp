#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

typedef struct node {
    int value;
    int level = 0;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

vector<int> in, post;

node_ptr create_tree(int post_left, int post_right, int in_left, int in_right){
    if (post_left > post_right) return nullptr;
    
    node_ptr n = new Node;
    n->value = post[post_right];
    
    int k = in_left;
    for (; in[k] != n->value; k++) continue;
    int leftnum = k - in_left;
    
    n->left = create_tree(post_left, post_left + leftnum - 1, in_left, k - 1);
    n->right = create_tree(post_left + leftnum, post_right - 1, k + 1, in_right);
    
    return n;
}

map<int, vector<int>> level_map;

void mark_level(node_ptr root){
    if (root == nullptr) return;
    
    if (root->left) root->left->level = root->level + 1;
    if (root->right) root->right->level = root->level + 1;
    
    mark_level(root->left);
    mark_level(root->right);
}

int maxlevel = -1;
void LevelOrder(node_ptr root){
    queue<node_ptr> q;
    q.push(root);
    
    while (!q.empty()) {
        node_ptr n = q.front(); q.pop();
        level_map[n->level].push_back(n->value);
        if (n->level > maxlevel) maxlevel = n->level;
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
}

void Output(){
    vector<int> ans;
    for (int i = 0; i <= maxlevel; i++){
        if (i % 2 == 0){
            reverse(level_map[i].begin(), level_map[i].end());
        }
        for (auto v : level_map[i]) ans.push_back(v);
    }
    
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
}

int n;
int main(){
    cin >> n;
    post.resize(n); in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    
    node_ptr root = create_tree(0, n - 1, 0, n - 1);
    mark_level(root);
    LevelOrder(root);
    Output();
    return 0;
}
