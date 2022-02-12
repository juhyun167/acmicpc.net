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
    int count = 0;

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
            count++;
        }
    }

    void union_set(T x, T y) {
        if (find_set(x) != find_set(y)) {
            link(find_set(x), find_set(y));
            count--;
        }
    }

    T find_set(T x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }

        return parent[x];
    }

    int count_sets() {
        return count;
    }

    int get_set_size(T x) {
        return size[find_set(x)];
    }
};

int main() {
	disjoint_set<int> ds;
	vector<int> vec;
	bool result = true;

	setup();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ds.make_set(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			if (k == 1) {
				ds.union_set(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> k;
		vec.push_back(k);
	}
	
	for (auto it = vec.begin(); it != vec.end() - 1; it++) {
		int u = *it, v = *(it + 1);

		if (ds.find_set(u) != ds.find_set(v)) {
			result = false;
			break;
		}
	}
	
	if (result) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}
