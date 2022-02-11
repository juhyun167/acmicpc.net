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

int solve(vector<edge>& vec, int n) {
	disjoint_set<int> ds;
	vector<edge> mst;
	int weight = 0, result = INT_MAX;

	sort(vec.begin(), vec.end());

	for (int i = 1; i <= n; i++) {
		ds.make_set(i);
	}
	for (const edge& e : vec) {
		if (ds.find_set(e.u) != ds.find_set(e.v)) {
			ds.union_set(e.u, e.v);
			weight += e.w;
			mst.push_back(e);
		}
	}

	for (const edge& e : mst) {
		result = min(result, weight - e.w);
	}

	return result;
}

int main() {
	vector<edge> vec;

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		vec.push_back(edge(a, b, c));
	}

	cout << solve(vec, n) << "\n";

	return 0;
}
