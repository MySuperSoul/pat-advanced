#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int n, m;

typedef struct node {
    int value;
    int level = 0;
    struct node* left = nullptr;
    struct node* right = nullptr;
    struct node* parent = nullptr;
}Node;

typedef Node* node_ptr;

map<int, node_ptr> node_map;
vector<int> Prev, in;

node_ptr create_tree(int in_left, int in_right, int pre_left, int pre_right){
    if (in_left > in_right) return nullptr;
    node_ptr n = new Node;
    n->value = Prev[pre_left];
    
    int k = in_left;
    for (; in[k] != n->value; k++) continue;
    int leftnum = k - in_left;
    
    n->left = create_tree(in_left, k - 1, pre_left + 1, pre_left + leftnum);
    n->right = create_tree(k + 1, in_right, pre_left + leftnum + 1, pre_right);
    
    if (n->left) {
        n->left->parent = n;
    }
    
    if (n->right) {
        n->right->parent = n;
    }
    
    return n;
}

void mark_level(node_ptr root){
    if (root == nullptr) return;
    if (root->left) root->left->level = root->level + 1;
    if (root->right) root->right->level = root->level + 1;
    node_map[root->value] = root;
    mark_level(root->left);
    mark_level(root->right);
}

int main()
{
    cin >> n >> m;
    Prev.resize(m);
    in.resize(m);
    
    for (int i = 0; i < m; i++){
        scanf("%d", &in[i]);
    }
    
    for (int i = 0; i < m; i++){
        scanf("%d", &Prev[i]);
    }
    
    node_ptr root = create_tree(0, m - 1, 0, m - 1);
    mark_level(root);
    
    for (int i = 0; i < n; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        bool flag1 = true; bool flag2 = true;
        
        if (node_map[v1] == nullptr) flag1 = false;
        if (node_map[v2] == nullptr) flag2 = false;
        
        if (!flag1 || !flag2){
            if (flag1 == false && flag2 == false){
                printf("ERROR: %d and %d are not found.\n", v1, v2);
            }else if (flag1 == false && flag2 == true){
                printf("ERROR: %d is not found.\n", v1);
            }else{
                printf("ERROR: %d is not found.\n", v2);
            }
        }else{
            node_ptr n1 = node_map[v1];
            node_ptr n2 = node_map[v2];
            int v1 = n1->value; int v2 = n2->value;
            node_ptr tmp;
            bool flag = false;
            
            int level1 = n1->level;
            int level2 = n2->level;
            
            if (level1 < level2){
                tmp = n2;
                while (tmp->level != level1) {
                    tmp = tmp->parent;
                }
                if (tmp == n1){
                    flag = true;
                    printf("%d is an ancestor of %d.\n", n1->value, n2->value);
                }
                
                if (!flag){
                    while (tmp->value != n1->value) {
                        tmp = tmp->parent;
                        n1 = n1->parent;
                    }
                    printf("LCA of %d and %d is %d.\n", v1, v2, tmp->value);
                }
            }else{
                tmp = n1;
                while (tmp->level != level2) {
                    tmp = tmp->parent;
                }
                if (tmp == n2){
                    flag = true;
                    printf("%d is an ancestor of %d.\n", n2->value, n1->value);
                }
                if (!flag){
                    while (tmp->value != n2->value) {
                        tmp = tmp->parent;
                        n2 = n2->parent;
                    }
                    printf("LCA of %d and %d is %d.\n", v1, v2, tmp->value);
                }
            }
        }
    }
    return 0;
}
