#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int n;
vector<int> Prev, Post;

typedef struct node{
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
} Node;

typedef Node* node_ptr;

bool flag = true;
node_ptr create_tree(int pre_left, int pre_right, int post_left, int post_right){
    if (pre_left > pre_right) return nullptr;
    node_ptr tmp = new Node;
    tmp->value = Prev[pre_left];
    
    if (pre_right - pre_left == 1 && Prev[pre_left] != Post[post_left]){
        flag = false;
    }
    
    if (pre_left != pre_right){
        int k = post_left;
        for (; Post[k] != Prev[pre_left + 1]; k++) continue;
        int leftnum = k - post_left + 1;
        tmp->left = create_tree(pre_left + 1, pre_left + leftnum, post_left, k);
        tmp->right = create_tree(pre_left + leftnum + 1, pre_right, k + 1, post_right - 1);
    }
    return tmp;
}

vector<int> ans;
void InOrder(node_ptr root){
    if (root == nullptr) return;
    InOrder(root->left);
    ans.push_back(root->value);
    InOrder(root->right);
}

void Output(){
    if (flag) printf("Yes \n");
    else printf("No \n");
    
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
}

int main(){
    cin >> n;
    Prev.resize(n); Post.resize(n);
    
    for (int i = 0; i < n; i++) scanf("%d", &Prev[i]);
    for (int i = 0; i < n; i++) scanf("%d", &Post[i]);
    
    node_ptr root = create_tree(0, n - 1, 0, n - 1);
    InOrder(root);
    Output();
    return 0;
}
