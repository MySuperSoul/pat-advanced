#include<iostream>
#include<vector>
using namespace std;

typedef struct node
{
	int value;
	struct node* left = NULL;
	struct node* right = NULL;
} Node;
typedef Node* node_ptr;

vector<int> insert_values;
vector<int> pre_order;
vector<int> mirror_pre_order;
vector<int> post_order;
int index;

node_ptr create_tree(node_ptr root, int value)
{
	if (root == NULL)
	{
		node_ptr new_node = new Node;
		new_node->value = value;
		return new_node;
	}

	if (value < root->value)
		root->left = create_tree(root->left, value);
	else
		root->right = create_tree(root->right, value);

	return root;
}

void pre_order_travel(node_ptr root)
{
	if (root == NULL) return;
	pre_order.push_back(root->value);
	pre_order_travel(root->left);
	pre_order_travel(root->right);
}

void mirror_pre_order_travel(node_ptr root)
{
	if (root == NULL) return;
	mirror_pre_order.push_back(root->value);
	mirror_pre_order_travel(root->right);
	mirror_pre_order_travel(root->left);
}

void post_order_travel(node_ptr root, bool is_mirror)
{
	if (root == NULL) return;
	
	if (!is_mirror)
	{
		post_order_travel(root->left, false);
		post_order_travel(root->right, false);
	}
	else
	{
		post_order_travel(root->right, true);
		post_order_travel(root->left, true);
	}
	post_order.push_back(root->value);
}

void output()
{
	cout << "YES" << endl;
	for (auto i = 0; i < post_order.size(); i++)
	{
		if (i == 0)
			cout << post_order.at(i);
		else
			cout << " " << post_order[i];
	}
}

bool cmp(bool is_mirror)
{
	for (auto i = 0; i < pre_order.size(); i++)
	{
		int value = (is_mirror == false) ? pre_order[i] : mirror_pre_order[i];
		if (value != insert_values[i])
			return false;
	}
	return true;
}

int main()
{
	int nodes_num;
	node_ptr root = NULL;
	cin >> nodes_num;

	for (int i = 0; i < nodes_num; i++)
	{
		int value;
		cin >> value;
		insert_values.push_back(value);
		root = create_tree(root, value);
	}

	pre_order_travel(root);
	mirror_pre_order_travel(root);

	if (cmp(false))
	{
		post_order_travel(root, false);
		output();
	}
	else
	{
		if (cmp(true))
		{
			post_order_travel(root, true);
			output();
		}
		else
			cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}