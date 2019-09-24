#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a % b);
}

struct node{
    int id;
    int value;
    int next;
};

node a[100005];
vector<node> Prev;
vector<node> thi;

int main()
{
    int start_a, start_b, n;
    cin >> start_a >> start_b >> n;

    for (int i = 0; i < n; i++){
        int s1, v, s2;
        scanf("%d %d %d", &s1, &v, &s2);
        a[s1].id = s1;
        a[s1].value = v;
        a[s1].next = s2;
    }

    int start = start_a;
    while (start != -1){
        Prev.push_back(a[start]);
        start = a[start].next;
    }

    start = start_b;
    while (start != -1){
        thi.push_back(a[start]);
        start = a[start].next;
    }

    vector<node> result;

    if (Prev.size() > thi.size()){
        int i = 0;
        int index = thi.size() - 1;
        for (i = 0; i < Prev.size(); i+=2){
            if (i + 1 < Prev.size()){
                result.push_back(Prev[i]);
                result.push_back(Prev[i + 1]);
                if (index >= 0) result.push_back(thi[index--]);
            }else{
                result.push_back(Prev[i]);
            }
        }
    }else{
        int i = 0;
        int index = Prev.size() - 1;
        for (i = 0; i < thi.size(); i+=2){
            if (i + 1 < thi.size()){
                result.push_back(thi[i]);
                result.push_back(thi[i + 1]);
                if (index >= 0) result.push_back(Prev[index--]);
            }else{
                result.push_back(thi[i]);
            }
        }
    }

    for (int i = 0; i < result.size() - 1; i++){
        node a = result[i];
        node b = result[i + 1];
        printf("%05d %d %05d\n", a.id, a.value, b.id);
    }

    node a = result[result.size() - 1];
    printf("%05d %d -1", a.id, a.value);
	return 0;
}
