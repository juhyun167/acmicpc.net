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

#define MAX		(100000 + 1)

int m, n, t, k, v;
int inorder[MAX], postorder[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void recursion(int left, int right,
				int post_left, int post_right) {
	int n, root;

	if (right == left) {
		cout << postorder[post_right] << " ";
		return;
	} else if (right - left < 0) {
		return;
	}

	for (int i = left; i <= right; i++) {
		if (inorder[i] == postorder[post_right]) {
			root = i;
			break;
		}
	}
	cout << postorder[post_right] << " ";
	n = root - left;
	recursion(left, root - 1, post_left, post_left + n - 1);
	recursion(root + 1, right, post_left + n, post_right - 1);
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	recursion(0, n - 1, 0, n - 1);
	cout << "\n";

	return 0;
}
