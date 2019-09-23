#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

typedef long long ll;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

void OutputForVector(vector<int>& ans){
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
}

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 0; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

#define maxn 105
#define maxinf 10000000

int n;
int initial[maxn];
int after[maxn];

int cnt = 1;
int heap[maxn];

void HeapSort(int i){
    int tmp = i;
    for (; ;){
        int child = tmp * 2;
        if (child > cnt) break;
        if (child + 1 <= cnt && heap[child + 1] > heap[child]) child = child + 1;
        
        if (heap[child] > heap[tmp]) {
            swap(heap[child], heap[tmp]);
            tmp = child;
        }
        else break;
    }
}

void MakeHeap() {
    heap[0] = maxinf;
    for (int i = 0; i < n; i++) heap[cnt++] = initial[i];
    cnt--;
    for (int i = cnt / 2; i >= 1; i--) {
        HeapSort(i);
    }
}

bool Check(){
    for (int i = 0; i < n; i++){
        if (after[i] != heap[i + 1]) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++) scanf("%d", &initial[i]);
    for (int i = 0; i < n; i++) scanf("%d", &after[i]);
    
    int i, j;
    bool insert_flag = true;
    
    for (i = 0; i < n - 1 && after[i] <= after[i + 1]; i++);
    for (j = i + 1; initial[j] == after[j] && j < n; j++);
    
    if (j != n) insert_flag = false;
    
    if (insert_flag){
        cout << "Insertion Sort" <<endl;
        sort(after, after + i + 2);
        for (int i = 0; i < n; i++){
            if (i == 0) cout << after[i];
            else cout << " " << after[i];
        }
    }else {
        cout << "Heap Sort" << endl;
        MakeHeap();
        
        for (; ;){
            if (Check()) break;
            else {
                swap(heap[1], heap[cnt--]);
                HeapSort(1);
            }
        }
        
        swap(heap[1], heap[cnt--]);
        HeapSort(1);
        
        for (int i = 1; i <= n; i++){
            if (i == 1) cout << heap[i];
            else cout << " " << heap[i];
        }
    }
    return 0;
}
