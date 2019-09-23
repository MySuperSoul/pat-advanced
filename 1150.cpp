#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define maxn 205
int Graph[maxn][maxn];
string Output[3] = {"(Not a TS cycle)", "(TS simple cycle)", "(TS cycle)"};

int n, m;
int minn = 1000000, minindex;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int v1, v2, c;
        scanf("%d %d %d", &v1, &v2, &c);
        Graph[v1][v2] = Graph[v2][v1] = c;
    }
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++){
        int cases;
        scanf("%d", &cases);
        vector<int> vec;
        set<int> s;
        
        for (int index = 0; index < cases; index++){
            int tmp;
            scanf("%d", &tmp);
            vec.push_back(tmp);
            s.insert(tmp);
        }
        
        int ts_circle; // 0 not, 1 simple, 2 TS
        
        if (vec.front() != vec.back()) ts_circle = 0;
        else if (s.size() != n) ts_circle = 0;
        else if (cases> n + 1) ts_circle = 2;
        else ts_circle = 1;
        
        int result = 0;
        bool result_flag = true;
        for (int index = 0; index < cases - 1; index++){
            if (Graph[vec[index]][vec[index + 1]] == 0){
                result_flag = false;
                break;
            }else result += Graph[vec[index]][vec[index + 1]];
        }
        
        if (result_flag == true){
            printf("Path %d: %d %s\n", i + 1, result, Output[ts_circle].c_str());
            if (result < minn && ts_circle != 0){
                minn = result;
                minindex = i + 1;
            }
        }else{
            printf("Path %d: NA %s\n", i + 1, Output[0].c_str());
        }
    }
    
    printf("Shortest Dist(%d) = %d", minindex, minn);
    return 0;
}
