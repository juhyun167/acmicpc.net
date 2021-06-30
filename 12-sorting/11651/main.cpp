#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t;
int arr[MAX + 1];

class Coord {
public:
	int x;
	int y;

	bool operator<(Coord other) {
		if (y == other.y) {
			return x < other.x;
		} else {
			return y < other.y;
		}
	}
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	vector<Coord> v;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		Coord c;

		cin >> c.x >> c.y;
		v.emplace_back(c);
	}
	sort(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		Coord c = (Coord) *it;

		cout << c.x << " " << c.y << "\n";
	}
	return 0;
}
