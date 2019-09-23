#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int people[101];
vector<int> state;

bool Check(int liar_1, int liar_2, int w1, int w2){
    fill(people, people + 101, 1); // 0 for wolf, 1 for people
    people[w1] = people[w2] = 0;
    
    for(int i = 1; i < state.size(); i++){
        int value = state[i];
        // not liar
        if (i == liar_1 || i == liar_2) value = -value;
        
        if (value > 0 && people[value] == 0) return false;
        if (value < 0 && people[abs(value)] == 1) return false;
    }
    return true;
}

int main()
{
    int num;
    cin >> num;
    
    state.resize(num + 5);
    
    for (int i = 1; i <= num; i++){
        scanf("%d", &state[i]);
    }
    
    for (int wolf1 = 1; wolf1 <= num; wolf1++){
        for (int wolf2 = wolf1 + 1; wolf2 <= num; wolf2++){
            // assume wolf1 is liar
            // point another liar
            for (int liar = 1; liar <= num; liar++){
                if (liar == wolf1 || liar == wolf2) continue;
                if (Check(wolf1, liar, wolf1, wolf2)){
                    cout << wolf1 << " " << wolf2;
                    return 0;
                }
            }
            //assume wolf2 is liar
            for (int liar = 1; liar <= num; liar++){
                if (liar == wolf2 || liar == wolf1) continue;
                if (Check(wolf2, liar, wolf1, wolf2)){
                    cout << wolf1 << " " << wolf2;
                    return 0;
                }
            }
        }
    }
    
    cout << "No Solution" << endl;
    return 0;
}
