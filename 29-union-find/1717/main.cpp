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

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

template <typename T>
class disjoint_set {
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;

    void link(T x, T y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

public:
    void make_set(T x) {
        if (parent.count(x) == 0) {
            parent[x] = x;
            rank[x] = 0;
        }
    }

    void union_set(T x, T y) {
        link(find_set(x), find_set(y));
    }

    T find_set(T x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }

        return parent[x];
    }
};

int main() {
	disjoint_set<int> ds;

	setup();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ds.make_set(i);
	}
	for (int i = 0; i < m; i++) {
		int op, x, y;

		cin >> op >> x >> y;
		if (op == 0) {
			ds.union_set(x, y);
		} else if (op == 1) {
			if (ds.find_set(x) == ds.find_set(y)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
