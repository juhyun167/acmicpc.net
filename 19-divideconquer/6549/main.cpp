#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t, k;
unsigned long long arr[MAX + 1];

template <typename T>
class segment_tree {
    vector<T> tree;
    int n;

public:
    segment_tree(T *arr, int n) : n(n) {
        tree.resize(n * 2);

        // insert leaf nodes in tree
        for (int i = 0; i < n; i++) {
            tree[n + i] = i;
        }

        // build the tree by calculating parents
        for (int i = n - 1; i > 0; i--) {
            tree[i] = (arr[tree[i << 1]] < arr[tree[i << 1 | 1]]) ?
                        tree[i << 1] : tree[i << 1 | 1];
        }
    }

    // get argmin on interval [l, r)
    int query(int l, int r) {
        int min = l, min2 = r - 1;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                min = (arr[min] < arr[tree[l]]) ?
                        min : tree[l];
                l++;
            }
            if (r & 1) {
                r--;
                min2 = (arr[min2] < arr[tree[r]]) ?
                        min2 : tree[r];
            }
        }
        return (arr[min] < arr[min2]) ? min : min2;
    }
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

unsigned long long solve(segment_tree<unsigned long long> &st,
							int start, int end) {
	int min = st.query(start, end + 1);
	unsigned long long size = arr[min] * (end - start + 1), size2;

	if (start < min) {
		size2 = solve(st, start, min - 1);
		size = (size > size2) ? size : size2;
	}
	if (min < end) {
		size2 = solve(st, min + 1, end);
		size = (size > size2) ? size : size2;
	}
	return size;
}

int main() {
	setup();
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		segment_tree<unsigned long long> st(arr, n);
		cout << solve(st, 0, n - 1) << "\n";
	}
	return 0;
}
