#include <bits/stdc++.h>
#include <cstdio>

#define maxn 1005

using namespace std;

typedef struct node
{
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
}Node;

typedef Node* node_ptr;

vector<node_ptr> vec;

int n, m;

vector<int> post;
void post_order(node_ptr root){
    if (root == nullptr) return;
    
    post_order(root->left);
    post_order(root->right);
    post.push_back(root->value);
}

// max heap
bool is_max_heap(node_ptr root){
    if (root == nullptr) return true;
    
    if (root->left){
        if (root->left->value > root->value) return false;
    }
    
    if (root->right){
        if (root->right->value > root->value) return false;
    }
    
    return is_max_heap(root->left) && is_max_heap(root->right);
}

// min heap
bool is_min_heap(node_ptr root){
    if (root == nullptr) return true;
    
    if (root->left){
        if (root->left->value < root->value) return false;
    }
    
    if (root->right){
        if (root->right->value < root->value) return false;
    }
    
    return is_min_heap(root->left) && is_min_heap(root->right);
}

int main()
{
    cin >> m >> n;
    vec.resize(n + 1);
    
    for (int i = 0; i < n + 1; i++){
        vec[i] = new Node;
    }
    
    for (int i = 0; i < m; i++){
        post.clear();
        for (int index = 1; index <= n; index++){
            scanf("%d", &vec[index]->value);
        }
        
        // create tree
        for (int index = 1; index <= n; index++){
            if (2 * index <= n) vec[index]->left = vec[2 * index];
            if (2 * index + 1 <= n) vec[index]->right = vec[2 * index + 1];
        }
        
        // judge
        if (is_max_heap(vec[1])) cout << "Max Heap" << endl;
        else if (is_min_heap(vec[1])) cout << "Min Heap" << endl;
        else cout << "Not Heap" << endl;
        
        // do post order
        post_order(vec[1]);
        for (int i = 0; i < post.size(); i++){
            if (i == 0) cout << post[i];
            else cout << " " << post[i];
        }
        cout << endl;
    }
    
    
    return 0;
}
