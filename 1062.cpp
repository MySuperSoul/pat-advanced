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
    int id;
    int virtue;
    int talent;
    int total;
}Node;

vector<Node> sage, nobleman, fool, small;

bool cmp(Node& a, Node& b){
    if(a.total == b.total){
        if(a.virtue == b.virtue) return a.id < b.id;
        else return a.virtue > b.virtue;
    }else{
        return a.total > b.total;
    }
}

void print(vector<Node>& vec){
    for(auto s : vec){
        cout << s.id << " " << s.virtue << " " << s.talent << endl;
    }
}

int main()
{
    int n, l, h;
    cin >> n >> l >> h;
    
    for(int i = 0; i < n; i++){
        Node n;
        scanf("%d %d %d", &n.id, &n.virtue, &n.talent);
        n.total = n.talent + n.virtue;
        if(n.talent < l || n.virtue < l) continue;
        else{
            if(n.talent >= h && n.virtue >= h) sage.push_back(n);
            else if(n.talent < h && n.virtue >= h) nobleman.push_back(n);
            else if(n.virtue >= n.talent) fool.push_back(n);
            else small.push_back(n);
        }
    }
    
    sort(sage.begin(), sage.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(fool.begin(), fool.end(), cmp);
    sort(small.begin(), small.end(), cmp);
    
    cout << sage.size() + nobleman.size() + fool.size() + small.size() << endl;
    print(sage);print(nobleman);print(fool);print(small);
    return 0;
}
/*
 14 60 80
 10000001 64 90
 10000002 90 60
 10000011 85 80
 10000003 85 80
 10000004 80 85
 10000005 82 77
 10000006 83 76
 10000007 90 78
 10000008 75 79
 10000009 59 90
 10000010 88 45
 10000012 80 100
 10000013 90 99
 10000014 66 60
 */
