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
	cout << setprecision(1);
}

struct point {
	double x, y;

	point(double x, double y) : x(x), y(y) {}
};

double area(vector<point>& p) {
	double result = 0.0, x1, x2, y1, y2;

	for (int i = 0; i < p.size() - 1; i++) {
		x1 = p[i].x, x2 = p[i + 1].x;
		y1 = p[i].y, y2 = p[i + 1].y;
		result += x1 * y2 - x2 * y1;
	}
	
	return fabs(result) / 2.0;
}

int main() {
	vector<point> p;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;

		cin >> x >> y;
		p.emplace_back(point(x, y));
	}
	p.emplace_back(p[0]);

	cout << area(p) << "\n";

	return 0;
}
