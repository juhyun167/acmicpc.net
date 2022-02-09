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

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

struct edge {
	int x, y;
	int64_t w;

	edge(int x, int y, int64_t w) : x(x), y(y), w(w) {}
};

bool compare(edge& lhs, edge& rhs) {
	return lhs.w > rhs.w;
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
	vector<edge> vec;
	disjoint_set<int> ds;
	int64_t ans = 0;

	setup();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		int64_t w;

		cin >> x >> y >> w;
		vec.emplace_back(edge(x, y, w));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 1; i <= n; i++) {
		ds.make_set(i);
	}
	for (const edge& e : vec) {
		int x = e.x, y = e.y;
		int64_t w = e.w;

		if (ds.find_set(x) != ds.find_set(y)) {
			ans += w * ds.get_set_size(x) * ds.get_set_size(y);
			ds.union_set(x, y);
		}
	}

	cout << ans << "\n";

	return 0;
}
