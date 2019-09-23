#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

int n;
vector<int> ans;

int fac1, fac2;

int x[2] = {1, -1};
int y[2] = {1, -1};

void FindFactors(){
    fac1 = sqrt(n);
    for (; ; fac1++){
        if (n % fac1 == 0) break;
    }

    fac2 = n / fac1;
    if (fac1 < fac2) swap(fac1, fac2);
}

int graph[10000][10000];
bool valid(int x, int y){
    if (x < 0 || x >= fac1 || y < 0 || y >= fac2) return false;
    if (graph[x][y] != 0) return false;
    return true;
}

int currentx = 0, currenty = -1;
int direction = 0; // 0, 1, 2, 3

void FillMap(vector<int>& ans){
    for (auto v : ans){
        for (; ;){
        if (direction == 0){
            currenty += 1;
            if (valid(currentx, currenty)) {
                graph[currentx][currenty] = v;
                break;
            }
            else {
                currenty -= 1;
                direction = 1;
            }
        }

        if (direction == 1){
            currentx += 1;
            if (valid(currentx, currenty)) {
                graph[currentx][currenty] = v;
                break;
            }
            else {
                currentx -= 1;
                direction = 2;
            }
        }

        if (direction == 2){
            currenty -= 1;
            if (valid(currentx, currenty)) {
                graph[currentx][currenty] = v;
                break;
            }
            else {
                currenty += 1;
                direction = 3;
            }
        }

        if (direction == 3){
            currentx -= 1;
            if (valid(currentx, currenty)) {
                graph[currentx][currenty] = v;
                break;
            }
            else {
                currentx += 1;
                direction = 0;
            }
        }
        }
    }
}

void Output(){
    for (int i = 0; i < fac1; i++){
        for (int j = 0; j < fac2; j++){
            if (j == 0) cout << graph[i][j];
            else cout << " " << graph[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        ans.push_back(v);
    }

    sort(ans.begin(), ans.end(), [](int& a, int& b){
        return a > b;
    });

    //DebugSTL(ans);
    FindFactors();
    FillMap(ans);
    Output();


    return 0;
}
