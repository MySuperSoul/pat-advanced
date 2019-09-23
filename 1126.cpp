#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define maxn 505
int n, m;

int graph[maxn][maxn];
int degrees[maxn];
int visit[maxn];

void dfs(int position){
    visit[position] = 1;
    for (int i = 1; i <= n; i++){
        if (visit[i] == 0 && graph[position][i] == 1) dfs(i);
    }
}

bool valid(){
    for (int i = 1; i <= n; i++){
        if (visit[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
        degrees[v1]++; degrees[v2]++;
    }
    
    int odd_num = 0, even_num = 0;
    for (int i = 1; i <= n; i++){
        if (i == 1) cout << degrees[i];
        else cout << " " << degrees[i];
        
        if (degrees[i] % 2) odd_num++;
        else if (degrees[i] % 2 == 0) even_num++;
    }
    cout << endl;
    
    dfs(1);
    
    if (!valid()) cout <<"Non-Eulerian";
    else {
        if (odd_num == 2) cout << "Semi-Eulerian";
        else if (odd_num == 0) cout << "Eulerian";
        else cout << "Non-Eulerian";
    }
    return 0;
}
