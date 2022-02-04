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

#define MAX		(3000 + 1)

int m, n, t, k, v;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

const double EPS = 1e-6;

struct point {
    double x, y;

	point() : x(0.0), y(0.0) {}
    point(double x, double y) : x(x), y(y) {}

    bool operator<(point& other) const {
        if (fabs(x - other.x) > EPS) {
            return x < other.x;
        }
        return y < other.y;
    }
    bool operator==(point& other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
	bool operator<=(point& other) const {
		return *this < other || *this == other;
	}
};

bool in_range(point p1, point p2, point p) {
	return (p1 <= p2 && p1 <= p && p <= p2) 
				|| (p2 <= p1 && p2 <= p && p <= p1);
}

struct line {
	double a, b, c;
};

void points_to_line(point p1, point p2, line& l) {
	if (fabs(p1.x - p2.x) < EPS) {
		l.a = 1.0, l.b = 0.0, l.c = -p1.x;
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

bool are_parallel(line l1, line l2) {
	return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool are_same(line l1, line l2) {
	return are_parallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

bool do_intersect(line l1, line l2, point& p) {
	if (are_parallel(l1, l2)) {
		return false;
	}
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) {
		p.y = -(l1.a * p.x + l1.c);
	} else {
		p.y = -(l2.a * p.x + l2.c);
	}

	return true;
}

struct line_segment {
	point p1, p2;

	line_segment() : p1(point()), p2(point()) {}

	line_segment(point p1, point p2) {
		if (p1 < p2) {
			this->p1 = p1, this->p2 = p2;
		} else {
			this->p1 = p2, this->p2 = p1;
		}
	}
};

bool do_intersect(line_segment ls1, line_segment ls2) {
	line l1, l2;
	point ints;		// intersection

	points_to_line(ls1.p1, ls1.p2, l1);
	points_to_line(ls2.p1, ls2.p2, l2);

	if (are_same(l1, l2)) {
		// two segments are on the same line
		if (in_range(ls1.p1, ls1.p2, ls2.p2)
				|| (in_range(ls2.p1, ls2.p2, ls1.p2))) {
			// have intersections
			return true;
		} else {
			// no intersection
			return false;
		}
	} else if (!do_intersect(l1, l2, ints)) {
		// two segments are parallel
		return false;
	} else {
		// two lines have a intersection
		if (in_range(ls1.p1, ls1.p2, ints)
				&& in_range(ls2.p1, ls2.p2, ints)) {
			// intersection is within two segments
			return true;
		} else {
			// intersection is outside two segments
			return false;
		}
	}

	return 0;
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
	vector<line_segment> vec;
	disjoint_set<int> ds;
	int max_el = INT_MIN;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		point p1, p2;

		cin >> x1 >> y1 >> x2 >> y2;
		p1 = point(x1, y1), p2 = point(x2, y2);
		vec.emplace_back(line_segment(p1, p2));

		ds.make_set(i);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (do_intersect(vec[i], vec[j])) {
				ds.union_set(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		max_el = max(ds.get_set_size(i), max_el);
	}

	cout << ds.count_sets() << "\n";
	cout << max_el << "\n";

	return 0;
}
