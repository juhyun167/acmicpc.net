#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int x1, x2, y1, y2, r1, r2;

	setup();
	cin >> t;
	for (int k = 0; k < t; k++) {
		double d;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1\n";
			continue;
		}
		d = dist(x1, y1, x2, y2);
		if (d > r1 + r2 || d < abs(r1 - r2)) {
			cout << "0\n";
		} else if (d == r1 + r2 || d == abs(r1 - r2)) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
	return 0;
}
