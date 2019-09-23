#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

typedef struct node{
    int value;
    int left = -1;
    int right = -1;
} Node;

vector<Node> node_vec;

int visit[25];

int FindRoot(){
    for (int i = 0; i < node_vec.size(); i++){
        if (visit[i] == 0) return i;
    }
    return -1;
}

int maxindex = -1;
int maxvalue;
void FindMaxIndex(int root, int index){
    Node n = node_vec[root];
    if (n.left != -1) FindMaxIndex(n.left, 2 * index);
    if (n.right != -1) FindMaxIndex(n.right, 2 * index + 1);
    if (maxindex < index) {
        maxindex = index;
        maxvalue = n.value;
    }
}

int main()
{
    int n;
    cin >> n;
    node_vec.resize(n + 5);
    
    for (int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 != "-"){
            int v1 = stoi(s1);
            node_vec[i].left = v1;
            visit[v1] = 1;
        }
        
        if (s2 != "-"){
            int v2 = stoi(s2);
            node_vec[i].right = v2;
            visit[v2] = 1;
        }
        
        node_vec[i].value = i;
    }
    
    int root = FindRoot();
    
    FindMaxIndex(root, 1);
    
    if (maxindex == n){
        printf("YES %d", maxvalue);
    }else{
        printf("NO %d", root);
    }
    
    return 0;
}
