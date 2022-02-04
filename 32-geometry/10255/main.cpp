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

int count_intersection(line_segment ls1, line_segment ls2,
							point& intersection) {
    line l1, l2;

    points_to_line(ls1.p1, ls1.p2, l1);
    points_to_line(ls2.p1, ls2.p2, l2);

    if (are_same(l1, l2)) {
        // two segments are on the same line
        if (in_range(ls1.p1, ls1.p2, ls2.p2)
                || (in_range(ls2.p1, ls2.p2, ls1.p2))) {
            // have intersection
            
			if (ls2.p1 < ls1.p1) {
				// make ls1.p1 smallest for convenience
				swap(ls1, ls2);
			}

			if (ls1.p1 < ls2.p2 && ls1.p2 == ls2.p1) {
				// two segments have only one intersection
				intersection = ls1.p2;
				return 1;
			} else {
				return 2;
			}
        } else {
            // no intersection
            return 0;
        }
    } else if (!do_intersect(l1, l2, intersection)) {
        // two segments are parallel
        return 0;
    } else {
        // two lines have a intersection
        if (in_range(ls1.p1, ls1.p2, intersection)
                && in_range(ls2.p1, ls2.p2, intersection)) {
            // intersection is within two segments
            return 1;
        } else {
            // intersection is outside two segments
            return 0;
        }
    }
}

bool point_in_rectangle(point p, vector<point>& rec_p) {
	return (rec_p[0].x <= p.x && p.x <= rec_p[3].x)
				&& (rec_p[0].y <= p.y && p.y <= rec_p[1].y);
}

bool line_segment_in_rectangle(line_segment ls, vector<point>& rec_p) {
	return point_in_rectangle(ls.p1, rec_p)
				&& point_in_rectangle(ls.p2, rec_p);
}

int mod(int a, int b) {
    int ret;

    if (b < 0) {
        return -mod(-a, -b);
    }
    ret = (a % b < 0) ? a % b + b : a % b;

    return ret;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		line_segment ls;
		vector<line_segment> rec;
		vector<point> rec_p;
		vector<point> intersection(4, point(INT_MAX, INT_MAX));
		int x1, y1, x2, y2;
		int rec_x1, rec_y1, rec_x3, rec_y3;
		int result = 0;

		cin >> rec_x1 >> rec_y1 >> rec_x3 >> rec_y3;
		rec_p.emplace_back(point(rec_x1, rec_y1));
		rec_p.emplace_back(point(rec_x1, rec_y3));
		rec_p.emplace_back(point(rec_x3, rec_y3));
		rec_p.emplace_back(point(rec_x3, rec_y1));

		cin >> x1 >> y1 >> x2 >> y2;
		ls = line_segment(point(x1, y1), point(x2, y2));

		sort(rec_p.begin(), rec_p.end());
		swap(rec_p[2], rec_p[3]);

		/**
		 * after sort, points are as follows.
		 *  
		 *  p[1]          p[2]
		 *  +----------------+
		 *  | rectangle      |
		 *  +----------------+
		 *  p[0]          p[3]
		 *
		 */

		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;

			rec.emplace_back(line_segment(rec_p[i], rec_p[j]));
		}

		for (int i = 0; i < 4; i++) {
			int count = count_intersection(ls, rec[i], intersection[i]);

			if (count == 2) {
				// infinite intersections
				result = 4;
				break;
			} else {
				if (count == 1) {
					for (int j = 0; j < i; j++) {
						if (intersection[i] == intersection[j]) {
							count = 0;
							break;
						}
					}
				}
				result += count;
			}
		}

		cout << result << "\n";
	}

	return 0;
}
