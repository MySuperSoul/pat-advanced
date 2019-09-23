#include <bits/stdc++.h>
#include <cstdio>

#define maxn 205
using namespace std;

int Graph[maxn][maxn];
int visit[maxn];
int nv, ne;

bool Check(vector<int>& vec, int index){
    int i;
    for (i = 0; i < vec.size(); i++){
        if (Graph[vec[i]][index] == 0) break;
    }
    
    if (i == vec.size()) return false;
    else return true;
}

int main()
{
    cin >> nv >> ne;
    
    for (int i = 0; i < ne; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        Graph[v1][v2] = Graph[v2][v1] = 1;
    }
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++){
        fill(visit, visit + maxn, 0);
        int cases;
        scanf("%d", &cases);
        vector<int> vec;
        for (int index = 0; index < cases; index++){
            int v;
            scanf("%d", &v);
            vec.push_back(v);
            visit[v] = 1;
        }
        
        // judge clique
        bool is_clique = true;
        for (int out = 0; out < vec.size(); out++){
            for (int in = out + 1; in < vec.size(); in++){
                int v1 = vec[out]; int v2 = vec[in];
                if (Graph[v1][v2] == 0){
                    is_clique = false;
                    break;
                }
            }
            if (!is_clique) break;
        }
        
        if (!is_clique){
            printf("Not a Clique\n");
        }else{
            bool valid = true;
            for (int index = 1; index <= nv; index++){
                if (!visit[index]){
                    if (Check(vec, index)) continue;
                    else{
                        valid = false;
                        break;
                    }
                }
            }
            
            if (valid) cout << "Yes" << endl;
            else cout << "Not Maximal" << endl;
        }
    }
    return 0;
}
