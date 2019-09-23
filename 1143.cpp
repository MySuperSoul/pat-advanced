#include <bits/stdc++.h>
#include <cstdio>

#define maxn 205
using namespace std;

typedef struct node {
    int value;
    int level = 0;
    struct node* left = nullptr;
    struct node* right = nullptr;
    struct node* parent = nullptr;
} Node;

typedef Node* node_ptr;
map<int, node_ptr> node_map;

void mark_level(node_ptr root){
    if (root == nullptr) return;
    
    if (root->left) root->left->level = root->level + 1;
    if (root->right) root->right->level = root->level + 1;
    node_map[root->value] = root;
    mark_level(root->left);
    mark_level(root->right);
}

vector<node_ptr> node_vec;

void Query(int n1, int n2){
    bool f1 = true, f2 = true;
    if (node_map[n1] == nullptr) f1 = false;
    if (node_map[n2] == nullptr) f2 = false;
    
    if (!f1 && !f2){
        printf("ERROR: %d and %d are not found.\n", n1, n2);
    }else if (!f1 && f2){
        printf("ERROR: %d is not found.\n", n1);
    }else if (f1 && !f2){
        printf("ERROR: %d is not found.\n", n2);
    }else{
        node_ptr p1 = node_map[n1]; node_ptr p2 = node_map[n2];
        int l1 = p1->level; int l2 = p2->level;
        bool inver = false;
        if (l1 > l2){ // keep p1 upper p2
            swap(p1, p2);
            swap(l1, l2);
            inver = true;
        }
        
        int value1 = p1->value; int value2 = p2->value;
        
        while (p2->level != p1->level) {
            p2 = p2->parent;
        }
        
        if (p1->value == p2->value){
            printf("%d is an ancestor of %d.\n", value1, value2);
        }else{
            while (p1->value != p2->value) {
                p1 = p1->parent;
                p2 = p2->parent;
            }
            
            printf("LCA of %d and %d is %d.\n", n1, n2, p1->value);
        }
    }
}

vector<int> p, in;
node_ptr create_tree(int pre_left, int pre_right, int in_left, int in_right){
    if (pre_left > pre_right) return nullptr;
    
    node_ptr n = new Node;
    n->value = p[pre_left];
    
    int k = in_left;
    for (; in[k] != n->value; k++) continue;
    int leftnum = k - in_left;
    
    n->left = create_tree(pre_left + 1, pre_left + leftnum, in_left, k - 1);
    n->right = create_tree(pre_left + leftnum + 1, pre_right, k + 1, in_right);
    
    if (n->left) n->left->parent = n;
    if (n->right) n->right->parent = n;
    
    return n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    p.resize(m);
    for (int i = 0; i < m; i++){
        scanf("%d", &p[i]);
    }
    
    in = p;
    sort(in.begin(), in.end());
    
    node_ptr root = create_tree(0, m - 1, 0, m - 1);
    mark_level(root);
    for (int i = 0; i < n; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        Query(v1, v2);
    }
    
    return 0;
}
