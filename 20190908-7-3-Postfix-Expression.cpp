#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct node {
    string val;
    int left, right;
}N[25];

int visit[25];

int n;

int Findroot(){
    for (int i = 1; i <= n; i++){
        if (visit[i] == 0) return i;
    }
    return -1;
}

string dfs(int root){
    node& n = N[root];
    
    if (n.left != -1 && n.right != -1) return "(" + dfs(n.left) + dfs(n.right) + n.val + ")";
    else if (n.left == -1 && n.right == -1) return "(" + n.val + ")";
    else if (n.left == -1 && n.right != -1) return "(" + n.val + dfs(n.right) + ")";
    else return "(" + dfs(n.left) + n.val + ")";
}

int main()
{
    cin >> n;
    
    string s;
    for (int i = 1; i <= n; i++){
        cin >> s;
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        N[i].val = s; N[i].left =v1; N[i].right = v2;
        if (v1 != -1) visit[v1] = 1;
        if (v2 != -1) visit[v2] = 1;
    }
    
    int root_pos = Findroot();
    
    string tmp = dfs(root_pos);
    cout << tmp;
    return 0;
}