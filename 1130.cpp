#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

#define maxn 30
int visit[maxn];
int root;
int n;

struct node{
	string value;
	int left = -1;
	int right = -1;
}N[maxn];

void findroot()
{
	for (int i = 1; i < maxn; i++){
		if (visit[i] == 0){
			root = i;
			return;
		}
	}
}

string dfs(int root){
	node n = N[root];
	if (n.left != -1 && n.right != -1) return "(" + dfs(n.left) + n.value + dfs(n.right) + ")";
	else if (n.left == -1 && n.right == -1) return n.value;
	else return "(" + n.value + dfs(n.right) + ")";
}

int main()
{
	cin >> n;
	
	string s;
	for (int i = 0; i < n; i++){
		int v1, v2;
		cin >> s >> v1 >> v2;
		
		N[i + 1].value = s;
		N[i + 1].left = v1;
		N[i + 1].right = v2;
		
		if (v1 != -1) visit[v1] = 1;
		if (v2 != -1) visit[v2] = 1;	
	}
	
	findroot();
	
	s = dfs(root);
	
	if (s[0] == '('){
		s = s.substr(1, s.size() - 2);
	}
	cout << s;
	return 0;
}