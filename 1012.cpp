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

typedef struct student
{
    /* data */
    int id, best;
    int score[4], rank[4];
} Student;

Student stu[20005];
int exists[1000000];
char output[4] = {'A', 'C', 'M', 'E'};
int flag = 0;

int main(int argc, const char** argv) {
    int n, m;
    cin >> n >> m;
    
    // read in the data and calculate the average grade
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3 + 0.5;
    }
    
    // calculate the rank for scores A C M E
    for(flag = 0; flag < 4; flag++){
        sort(stu, stu + n, [](Student& a, Student& b) -> bool {return a.score[flag] > b.score[flag];});
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++){
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i - 1].score[flag]) stu[i].rank[flag] = stu[i - 1].rank[flag];
        }
    }
    
    // store the best rank for A C M E
    for(int i = 0; i < n; i++){
        stu[i].best = 0;
        int min_rank = stu[i].rank[0];
        for(int j = 0; j < 4; j++){
            if(stu[i].rank[j] < min_rank){
                min_rank = stu[i].rank[j];
                stu[i].best = j;
            }
        }
        exists[stu[i].id] = i + 1;
    }
    
    // read in the test data
    for(int i = 0; i < m; i++){
        int t;
        scanf("%d", &t);
        if (exists[t] == 0){
            cout << "N/A" << endl;
        }else{
            int id = exists[t] - 1;
            int best = stu[id].best;
            cout << stu[id].rank[best] << " " << output[best] << endl;
        }
    }
    
    return 0;
}
