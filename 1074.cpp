#include <iostream>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;

typedef struct node{
    int start_pos;
    int end_pos;
    int value;
}Node;

Node node_store[100001];

int main()
{
    int start_p, n, k;
    cin >> start_p >> n >> k;
    
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        scanf("%d%d", &node_store[t].value, &node_store[t].end_pos);
        node_store[t].start_pos = t;
    }
    
    vector<Node> node_prev;
    vector<Node> node_now;
    
    while (start_p != -1) {
        node_prev.push_back(node_store[start_p]);
        start_p = node_store[start_p].end_pos;
    }
    
    for(int i = 0; i < node_prev.size(); i += k){
        if(i + k > node_prev.size()){
            for(; i < node_prev.size(); i++) node_now.push_back(node_prev[i]);
            break;
        }else{
            for(int j = i + k - 1; j >= i; j--) node_now.push_back(node_prev[j]);
        }
    }
    
    if(node_now.size() != 1){
        for(int i = 0; i < node_now.size() - 1; i++){
            node_now[i].end_pos = node_now[i + 1].start_pos;
            printf("%05d %d %05d\n", node_now[i].start_pos, node_now[i].value, node_now[i].end_pos);
        }
    }
    
    auto end_p = node_now.size() - 1;
    printf("%05d %d -1", node_now[end_p].start_pos, node_now[end_p].value);
    
    return 0;
}

/*
 00100 6 3
 00000 4 99999
 00100 1 12309
 68237 6 -1
 33218 3 00000
 99999 5 68237
 12309 2 33218
 
 00100 1 3
 00100 3 -1
 */
