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

struct edge {
    int u, v;
	double w;

    edge(int u, int v, double w) : u(u), v(v), w(w) {}

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

double kruskal(vector<edge>& vec, int n) {
    disjoint_set<double> ds;
    double result = 0.0;

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

struct pos {
	double x, y;

	pos() : x(0.0), y(0.0) {}
	pos(double x, double y) : x(x), y(y) {}
};

double dist(pos& p1, pos& p2) {
	return sqrt(fabs(p1.x - p2.x) * fabs(p1.x - p2.x)
				+ fabs(p1.y - p2.y) * fabs(p1.y - p2.y));
}

int main() {
	vector<pos> pvec;
	vector<edge> evec;

	setup();
	cin >> n;
	pvec.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> pvec[i].x >> pvec[i].y;
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			evec.push_back(edge(i, j, dist(pvec[i], pvec[j])));
		}
	}

	cout << kruskal(evec, n) << "\n";

	return 0;
}
