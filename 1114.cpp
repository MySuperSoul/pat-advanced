#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

unordered_map<int, vector<int>> familes;
unordered_set<int> all_people;

struct node{
    int sets = 0;
    int area = 0;
} N[10005];

struct result{
    int id;
    int number;
    double avg_set;
    double avg_area;

    bool operator< (const result& a) const{
        if (avg_area == a.avg_area){
            return id < a.id;
        }else {
            return avg_area > a.avg_area;
        }
    }
};

#define maxn 10005
int S[maxn];

int Find(int r){
    if (S[r] < 0) return r;
    else return S[r] = Find(S[r]);
}

void Union(int r1, int r2){
    int real_r1, real_r2;
    real_r1 = Find(r1);
    real_r2 = Find(r2);

    if (real_r1 == real_r2) return;

    S[real_r2] = real_r1;

    N[real_r1].area += N[real_r2].area;
    N[real_r1].sets += N[real_r2].sets;
}

int main()
{
    fill(S, S + maxn, -1);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int thi, father, mother;
        scanf("%d %d %d", &thi, &father, &mother);
        all_people.insert(thi);
        if (father != -1) {
            Union(thi, father);
            all_people.insert(father);
        }
        if (mother != -1) {
            Union(thi, mother);
            all_people.insert(mother);
        }

        int childs;
        scanf("%d", &childs);

        for (int j = 0; j < childs; j++){
            int v;
            scanf("%d", &v);
            all_people.insert(v);
            Union(thi, v);
        }

        int s, area;
        scanf("%d %d", &s, &area);

        int current_root = Find(thi);
        N[current_root].area += area;
        N[current_root].sets += s;
    }

    for (auto v : all_people){
        familes[Find(v)].push_back(v);
    }

    set<result> f_s;

    for (auto iter = familes.begin(); iter != familes.end(); iter++){
        result r;
        sort(iter->second.begin(), iter->second.end());
        r.id = iter->second.front();
        r.number = iter->second.size();
        r.avg_area = (1.0 * N[Find(iter->first)].area) / r.number;
        r.avg_set = (1.0 * N[Find(iter->first)].sets) / r.number;
        f_s.insert(r);
    }

    cout << f_s.size() << endl;

    for (auto v : f_s){
        printf("%04d %d %.3f %.3f\n", v.id, v.number, v.avg_set, v.avg_area);
    }
    return 0;
}
