#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<int> p, in;

typedef struct node {
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

node_ptr create_tree(int pre_left, int pre_right, int in_left, int in_right){
    if (pre_left > pre_right) return nullptr;
    
    node_ptr n = new Node;
    n->value = p[pre_left];
    
    int k = in_left;
    for (; in[k] != n->value; k++) continue;
    int leftnum = k - in_left;
    
    n->left = create_tree(pre_left + 1, pre_left + leftnum, in_left, k - 1);
    n->right = create_tree(pre_left + leftnum + 1, pre_right, k + 1, in_right);
    
    return n;
}

vector<int> post;
void post_order(node_ptr n){
    if (n == nullptr) return;
    post_order(n->left);
    post_order(n->right);
    post.push_back(n->value);
}

int main(){
    int num;
    cin >> num;
    
    p.resize(num); in.resize(num);
    
    for (int i = 0; i < num; i++){
        scanf("%d", &p[i]);
    }
    
    for (int i = 0; i < num; i++){
        scanf("%d", &in[i]);
    }
    
    node_ptr n = create_tree(0, num - 1, 0, num - 1);
    post_order(n);
    
    cout << post.front();
    return 0;
}
