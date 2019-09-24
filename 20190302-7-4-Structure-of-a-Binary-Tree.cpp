#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n;

typedef struct node {
    int val;
    struct node* left = nullptr;
    struct node* right = nullptr;
    struct node* parent = nullptr;
    bool is_full = false;
    int level = 0;
}Node;

typedef Node* node_ptr;

vector<int> post, in;

node_ptr create_tree(int in_left, int in_right, int post_left, int post_right){
    if (in_left > in_right) return nullptr;
    
    node_ptr n = new Node;
    n->val = post[post_right];
    
    int k = in_left;
    for ( ; in[k] != post[post_right]; k++) continue;
    int left_subnum = k - in_left;
    
    n->left = create_tree(in_left, k - 1, post_left, post_left + left_subnum - 1);
    n->right = create_tree(k + 1, in_right, post_left + left_subnum, post_right - 1);
    return n;
}

map<int, node_ptr> m;

void mark(node_ptr root){
    if (root == nullptr) return;
    
    m[root->val] = root;
    if (root->left != nullptr) {root->left->level = root->level + 1; root->left->parent = root;}
    if (root->right != nullptr) {root->right->level = root->level + 1; root->right->parent = root;}
    if (root->left && root->right) root->is_full = true;
    mark(root->left);
    mark(root->right);
}

bool fulltree(){
    for (auto v : m){
        if (v.second->is_full == false && !(v.second->left == nullptr && v.second->right == nullptr)) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    post.resize(n);
    in.resize(n);
    
    for (int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    
    for (int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    
    node_ptr root = create_tree(0, n - 1, 0, n - 1);
    
    mark(root);
    
    int q;
    scanf("%d\n", &q);
    string s;
    
    for (int i = 0; i < q; i++){
        getline(cin, s);
        if (s.back() == 't'){
            auto blank_p = s.find_first_of(" ");
            int tmp = stoi(s.substr(0, blank_p));
            if (root->val == tmp) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else if (s.back() == 's'){
            auto p1 = s.find(" and");
            auto p2 = s.find(" are");
            int n1 = stoi(s.substr(0, p1));
            auto start_p = p1 + 5;
            int n2 = stoi(s.substr(start_p, p2 - start_p));
            if (m[n1]->parent == m[n2]->parent) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else if (s.back() == 'l'){
            auto p1 = s.find(" and");
            auto p2 = s.find(" are");
            int n1 = stoi(s.substr(0, p1));
            auto start_p = p1 + 5;
            int n2 = stoi(s.substr(start_p, p2 - start_p));
            if (m[n1]->level == m[n2]->level) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else if (s.back() == 'e'){
            if (fulltree() == true) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            auto start_p = s.find_first_of(" ");
            int n1 = stoi(s.substr(0, start_p));
            start_p = s.find_last_of(" ");
            int n2 = stoi(s.substr(start_p + 1));
            
            if (s.find("parent") != -1){
                if (m[n2]->parent == m[n1]) cout << "Yes" << endl;
                else cout << "No" << endl;
            }else if (s.find("left") != -1){
                if (m[n2]->left == m[n1]) cout << "Yes" << endl;
                else cout << "No" << endl;
            }else{
                if (m[n2]->right == m[n1]) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
    
    return 0;
}