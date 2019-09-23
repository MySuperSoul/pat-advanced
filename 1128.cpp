#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

int n;
int main()
{
	cin >> n;
	
	while(n--){
		int num;
		scanf("%d", &num);
		
		unordered_set<int> s;
		vector<int> vec;
		
		for (int i = 0; i < num; i++){
			int v;
			scanf("%d", &v);
			s.insert(v);
			vec.push_back(v);
		}
		
		if (s.size() != num) cout << "NO" << endl;
		else {
			bool flag = true;
			for (int i = 0; i < vec.size(); i++){
				for (int j = i + 1; j < vec.size(); j++){
					if (abs(vec[i] - vec[j]) == j - i){
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}