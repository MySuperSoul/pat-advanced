#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector<int> in, post;

typedef struct node {
    int val;
    struct node* left = nullptr;
    struct node* right = nullptr;
}Node;

typedef Node* node_ptr;

node_ptr create_tree(int in_left, int in_right, int post_left, int post_right){
    if (in_left > in_right) return nullptr;
    node_ptr n = new Node;
    n->val = post[post_right];
    
    int k = in_left;
    for (k = in_left; in[k] != n->val; k++) continue;
    int left_treenum = k - in_left;
    
    n->left = create_tree(in_left, k - 1, post_left, post_left + left_treenum - 1);
    n->right = create_tree(k + 1, in_right, post_left + left_treenum, post_right - 1);
    return n;
}

vector<int> ans;
queue<node_ptr> q;

void level(node_ptr root){
    q.push(root);
    
    while (!q.empty()) {
        node_ptr n = q.front(); q.pop();
        ans.push_back(n->val);
        
        if (n->left != nullptr) q.push(n->left);
        if (n->right != nullptr) q.push(n->right);
    }
}

int main()
{
    int num;
    cin >> num;
    
    for(int i = 0; i < num; i++){
        int v;
        scanf("%d", &v);
        post.push_back(v);
    }
    
    for(int i = 0; i < num; i++){
        int v;
        scanf("%d", &v);
        in.push_back(v);
    }
    
    node_ptr root = nullptr;
    root = create_tree(0, num - 1, 0, num - 1);
    
    level(root);
    
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    return 0;
}
