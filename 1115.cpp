#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef struct node{
    int value;
    int level = 0;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

node_ptr Insert(node_ptr root, int value){
    if (root == nullptr){
        node_ptr n = new Node;
        n->value = value;
        return n;
    }

    if (value <= root->value) root->left = Insert(root->left, value);
    else root->right = Insert(root->right, value);

    return root;
}

node_ptr create_tree(vector<int>& ans){
    node_ptr root = nullptr;
    for (auto v : ans) root = Insert(root, v);
    return root;
}

unordered_map<int, int> m;
int maxlevel = -1;
void mark_level(node_ptr root){
    if (root == nullptr) return;
    if (root->left) root->left->level = root->level + 1;
    if (root->right) root->right->level = root->level + 1;

    if (root->level > maxlevel) maxlevel = root->level;
    m[root->level] += 1;

    mark_level(root->left);
    mark_level(root->right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> ans;
    ans.resize(n);

    for (int i = 0; i < n; i++) scanf("%d", &ans[i]);
    node_ptr root = create_tree(ans);
    mark_level(root);

    int low = m[maxlevel];
    int high = m[maxlevel - 1];

    printf("%d + %d = %d", low, high, low + high);
    return 0;
}
