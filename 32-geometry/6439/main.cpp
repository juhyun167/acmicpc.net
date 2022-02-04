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
    point ints;     // intersection

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

bool point_in_rectangle(point p, vector<point>& rec_p) {
	return (rec_p[0].x <= p.x && p.x <= rec_p[3].x)
				&& (rec_p[0].y <= p.y && p.y <= rec_p[1].y);
}

bool line_segment_in_rectangle(line_segment ls, vector<point>& rec_p) {
	return point_in_rectangle(ls.p1, rec_p)
				&& point_in_rectangle(ls.p2, rec_p);
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		line_segment ls;
		line_segment rec[4];
		vector<point> rec_p;
		int x1, y1, x2, y2;
		int rec_x1, rec_y1, rec_x3, rec_y3;
		bool result = false;

		cin >> x1 >> y1 >> x2 >> y2;
		ls = line_segment(point(x1, y1), point(x2, y2));

		cin >> rec_x1 >> rec_y1 >> rec_x3 >> rec_y3;
		rec_p.emplace_back(point(rec_x1, rec_y1));
		rec_p.emplace_back(point(rec_x1, rec_y3));
		rec_p.emplace_back(point(rec_x3, rec_y3));
		rec_p.emplace_back(point(rec_x3, rec_y1));

		sort(rec_p.begin(), rec_p.end());
		swap(rec_p[2], rec_p[3]);

		/* after sort, points are as follows.
		 *  
		 *  p[1]          p[2]
		 *  +----------------+
		 *  | rectangle      |
		 *  +----------------+
		 *  p[0]          p[3]
		 *
		 */

		if (line_segment_in_rectangle(ls, rec_p)) {
			cout << "T\n";
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;

			rec[i] = line_segment(rec_p[i], rec_p[j]);
		}

		for (int i = 0; i < 4; i++) {
			if (do_intersect(ls, rec[i])) {
				result = true;
				break;
			}
		}

		if (result) {
			cout << "T\n";
		} else {
			cout << "F\n";
		}
	}

	return 0;
}
