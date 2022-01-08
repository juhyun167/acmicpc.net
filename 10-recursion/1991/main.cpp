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
#include <iomanip>
using namespace std;

#define MAX		(26 + 1)

int m, n, t, k, v;

struct node {
	char value;
	node *left, *right;

	node(int n) {
		value = (char) n + 'A';
		left = right = NULL;
	}
};

vector<node *> vec;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void preorder(node *n) {
	if (n == NULL) {
		return;
	}
	cout << n->value;
	preorder(n->left);
	preorder(n->right);
}

void inorder(node *n) {
	if (n == NULL) {
		return;
	}
	inorder(n->left);
	cout << n->value;
	inorder(n->right);
}

void postorder(node *n) {
	if (n == NULL) {
		return;
	}
	postorder(n->left);
	postorder(n->right);
	cout << n->value;
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		node *n = new node(i);
		vec.emplace_back(n);
	}
	for (int i = 0; i < n; i++) {
		char c, l, r;

		cin >> c >> l >> r;
		if (l != '.') {
			vec[c - 'A']->left = vec[l - 'A'];
		}
		if (r != '.') {
			vec[c - 'A']->right = vec[r - 'A'];
		}
	}

	preorder(vec[0]);
	cout << "\n";
	inorder(vec[0]);
	cout << "\n";
	postorder(vec[0]);
	cout << "\n";

	return 0;
}
