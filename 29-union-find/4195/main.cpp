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
	unordered_map<T, int> size;

    void link(T x, T y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
			size[x] += size[y];
        } else {
            parent[x] = y;
			size[y] += size[x];
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
			size[x] = 1;
        }
    }

    void union_set(T x, T y) {
		if (find_set(x) != find_set(y)) {
			link(find_set(x), find_set(y));
		}
    }

    T find_set(T x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }

        return parent[x];
    }

	int get_set_size(T x) {
		return size[find_set(x)];
	}
};

int main() {
	setup();
	cin >> t;
	while (t--) {
		disjoint_set<string> ds;

		cin >> n;
		for (int i = 0; i < n; i++) {
			string s1, s2;

			cin >> s1 >> s2;
			ds.make_set(s1);
			ds.make_set(s2);

			ds.union_set(s1, s2);
			cout << ds.get_set_size(s1) << "\n";
		}
	}

	return 0;
}
