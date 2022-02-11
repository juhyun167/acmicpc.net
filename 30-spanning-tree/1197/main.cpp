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

int m, n, t, k, v, e;

struct edge {
	int u, v, w;

	edge(int u, int v, int w) : u(u), v(v), w(w) {}

	bool operator<(const edge& other) const {
		return w < other.w;
	}
};

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

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int kruskal(vector<edge>& vec, int n) {
	disjoint_set<int> ds;
	int result = 0;

	sort(vec.begin(), vec.end());

	for (int i = 1; i <= n; i++) {
		ds.make_set(i);
	}
	for (const edge& e : vec) {
		if (ds.find_set(e.u) != ds.find_set(e.v)) {
			ds.union_set(e.u, e.v);
			result += e.w;
		}
	}

	return result;
}

int main() {
	vector<edge> vec;

	setup();
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		vec.push_back(edge(u, v, w));
	}

	cout << kruskal(vec, v) << "\n";

	return 0;
}
