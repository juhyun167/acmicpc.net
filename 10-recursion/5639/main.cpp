#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include <iomanip>
using namespace std;

#define MAX		(1000000 + 1)

int m, n, t, k, v;
int arr[MAX];

struct Node {
	int n;
	Node *left, *right, *parent;

	Node(int n) : n(n) {
		left = right = parent = NULL;
	}
};

class BST {
public:
	Node *root;

	BST() : root(NULL) {}

	void insert(int n);
};

void BST::insert(int n) {
	Node *newnode = new Node(n);
	Node *x = this->root, *y = NULL;

	if (x == NULL) {
		this->root = newnode;
		return;
	}
	while (x != NULL) {
		y = x;
		x = (n < x->n) ? x->left : x->right;
	}
	if (n < y->n) {
		y->left = newnode;
	} else {
		y->right = newnode;
	}
}

void postorder(Node *node) {
	if (node->left != NULL) {
		postorder(node->left);
	}
	if (node->right != NULL) {
		postorder(node->right);
	}
	cout << node->n << "\n";
}

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	BST bst;
	int n;

	while (cin >> n) {
		bst.insert(n);
	}
	postorder(bst.root);

	return 0;
}
