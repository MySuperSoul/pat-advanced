#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;

typedef struct node {
	string value;
	struct node* left = nullptr;
	struct node* right = nullptr;
	int color = -1; // 0 for black, 1 for red
} Node;

typedef Node* node_ptr;

node_ptr N[35];
int Count = 0;

node_ptr Insert(node_ptr root, string value) {
	if (root == nullptr) {
		node_ptr n = N[Count++];
		n->left = n->right = nullptr;
		n->value = value;
		if (value.front() == '-') n->color = 1;
		else n->color = 0;
		return n;
	}

	if (abs(stoi(value)) < abs(stoi(root->value))) root->left = Insert(root->left, value);
	else
	{
		root->right = Insert(root->right, value);
	}

	return root;
}

node_ptr create_tree(vector<string>& ans) {
	node_ptr root = nullptr;
	for (auto v : ans) {
		root = Insert(root, v);
	}
	return root;
}

bool check2(node_ptr root) {
	return root->color == 0;
}

bool check4() {
	for (int i = 0; i < Count; i++) {
		node_ptr root = N[i];
		if (root->color == 1) {
			if (root->left && root->left->color == 1) return false;
			if (root->right && root->right->color == 1) return false;
		}
	}
	return true;
}

// dfs all the paths in this tree
vector<int> ans;

void dfs(node_ptr n, int cnt) {
	if (n == nullptr) {
		ans.push_back(cnt + 1);
		return;
	}

	// non leaf
	if (n->color == 0) {
		dfs(n->right, cnt + 1);
		dfs(n->left, cnt + 1);
	}
	else {
		dfs(n->right, cnt);
		dfs(n->left, cnt);
	}
}

bool check5() {
	for (int i = 0; i < Count; i++) {
		ans.clear();
		node_ptr n = N[i];
		dfs(n, 0);
		sort(ans.begin(), ans.end());
		if (ans.front() != ans.back()) {
			return false;
		}
	}
	return true;
}

int n;
int main()
{
	cin >> n;

	for (int i = 0; i < 33; i++) N[i] = new Node;

	while (n--)
	{
		Count = 0;
		int num;
		scanf("%d", &num);

		vector<string> vec;
		vec.resize(num);

		for (int i = 0; i < num; i++) {
			cin >> vec[i];
		}

		node_ptr n = create_tree(vec);

		// p2
		if (n == nullptr) cout << "No" << endl;
		if (check2(n) && check4() && check5()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	//system("pause");
	return 0;
}