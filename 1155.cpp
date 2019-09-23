#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// dfs, bfs, dp, union-find, binary-search, heap, queue, priority_queue, tree
typedef struct node {
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
}Node;

typedef Node* node_ptr;

vector<node_ptr> node_vec;

// dfs the tree to find path
vector<int> path;
void print_path(node_ptr root)
{
    path.push_back(root->value);
    
    if (root->left == nullptr && root->right == nullptr){
        for (int i = 0; i < path.size(); i++){
            if (i == 0) cout << path[i];
            else cout << " " << path[i];
        }
        cout << endl;
    }
    if (root->right != nullptr) print_path(root->right);
    if (root->left != nullptr) print_path(root->left);
    path.pop_back();
}

// dfs to detect max heap
bool is_max_heap(node_ptr root){
    if (root == nullptr) return true;
    
    if (root->left != nullptr){
        if (root->value < root->left->value) return false;
    }
    
    if (root->right != nullptr){
        if (root->value < root->right->value) return false;
    }
    
    return is_max_heap(root->left) && is_max_heap(root->right);
}

bool is_min_heap(node_ptr root){
    if (root == nullptr) return true;
    
    if (root->left != nullptr){
        if (root->value > root->left->value) return false;
    }
    
    if (root->right != nullptr){
        if (root->value > root->right->value) return false;
    }
    
    return is_min_heap(root->left) && is_min_heap(root->right);
}

int main()
{
    int n;
    cin >> n;
    node_vec.resize(n + 1);
    
    for (int i = 1; i <= n; i++){
        node_vec[i] = new Node;
        scanf("%d", &node_vec[i]->value);
    }
    
    // create the tree using array here
    for (int i = 1; i <= n; i++){
        if (2 * i <= n) node_vec[i]->left = node_vec[2 * i];
        if (2 * i + 1 <= n) node_vec[i]->right = node_vec[2 * i + 1];
    }
    
    print_path(node_vec[1]);
    
    if (is_max_heap(node_vec[1])){
        cout << "Max Heap";
    }else if (is_min_heap(node_vec[1])){
        cout << "Min Heap";
    }else {
        cout << "Not Heap";
    }
    return 0;
}
