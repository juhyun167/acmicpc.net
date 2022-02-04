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

int main() {
	line l[2];
	point p[2][2], intersect;

	setup();
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int x, y;
			
			cin >> x >> y;
			p[i][j] = point(x, y);
		}
		if (p[i][1] < p[i][0]) {
			swap(p[i][0], p[i][1]);
		}
		points_to_line(p[i][0], p[i][1], l[i]);
	}

	if (are_same(l[0], l[1])) {
		// two segments are on the same line
		if (in_range(p[0][0], p[0][1], p[1][1])
				|| (in_range(p[1][0], p[1][1], p[0][1]))) {
			// have intersections
			cout << "1\n";
		} else {
			// no intersection
			cout << "0\n";
		}
	} else if (!do_intersect(l[0], l[1], intersect)) {
		// two segments are parallel
		cout << "0\n";
	} else {
		// two lines have a intersection
		if (in_range(p[0][0], p[0][1], intersect)
				&& in_range(p[1][0], p[1][1], intersect)) {
			// intersection is within two segments
			cout << "1\n";
		} else {
			// intersection is outside two segments
			cout << "0\n";
		}
	}

	return 0;
}
