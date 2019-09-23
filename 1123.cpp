#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

typedef struct node{
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

int GetMaxHeight(node_ptr n){
    if (n == nullptr) return 1;
    return max(GetMaxHeight(n->left), GetMaxHeight(n->right)) + 1;
}

node_ptr llrotation(node_ptr root){
    node_ptr tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

node_ptr rrrotation(node_ptr root){
    node_ptr tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

node_ptr lrrotation(node_ptr root){
    root->left = llrotation(root->left);
    root = rrrotation(root);
    return root;
}

node_ptr rlrotation(node_ptr root){
    root->right = rrrotation(root->right);
    root = llrotation(root);
    return root;
}

node_ptr Insert(node_ptr root, int value){
    if (root == nullptr){
        root = new Node;
        root->value = value;
        return root;
    }
    
    if (value < root->value) root->left = Insert(root->left, value);
    if (value > root->value) root->right = Insert(root->right, value);
    
    // update the avl tree
    int left_level = GetMaxHeight(root->left);
    int right_level = GetMaxHeight(root->right);
    
    if (abs(left_level - right_level) >= 2){ // need updating
        if (value < root->value){
            if (value < root->left->value) root = rrrotation(root);
            else root = lrrotation(root);
        } // left tree
        else{ // right tree
            if (value < root->right->value) root = rlrotation(root);
            else root = llrotation(root);
        }
    }
    
    return root;
}

node_ptr create_tree(vector<int>& ans){
    node_ptr root = nullptr;
    for (auto v : ans) root = Insert(root, v);
    return root;
}

vector<int> result;
void LevelOrder(node_ptr root){
    queue<node_ptr> q;
    q.push(root);
    
    while (!q.empty()) {
        node_ptr n = q.front(); q.pop();
        result.push_back(n->value);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
    
    for (int i = 0; i < result.size(); i++){
        if (i == 0) printf("%d", result[i]);
        else printf(" %d", result[i]);
    }
    cout << endl;
}

int maxindex = -1;
void FindMaxIndex(node_ptr root, int index){
    if (root == nullptr) return;
    
    if (root->left == nullptr && root->right == nullptr){ // leaf
        if (index > maxindex) maxindex = index;
    }
    
    FindMaxIndex(root->left, 2 * index);
    FindMaxIndex(root->right, 2 * index + 1);
}

int main(){
    int n;
    cin >> n;
    
    vector<int> ans;
    ans.resize(n);
    
    for (int i = 0; i < n; i++){
        scanf("%d", &ans[i]);
    }
    
    node_ptr root = create_tree(ans);
    
    LevelOrder(root);
    FindMaxIndex(root, 1);
    
    if (maxindex == n) cout << "YES";
    else cout << "NO";
    return 0;
}
