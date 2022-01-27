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

#define MAX		(13 + 1)

int m, n, t, k, v;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

struct Point {
	int y, x;

	Point(int y, int x) : y(y), x(x) {}
};

inline int dist(const Point& p1, const Point& p2) {
	return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}

vector<Point> house, chicken;
bool visited[MAX];
int result = INT_MAX;

int get_total_dist(vector<int>& vec) {
	int result = 0;

	for (const Point& p : house) {
		int min_dist = INT_MAX;

		for (const int x : vec) {
			min_dist = min(min_dist, dist(p, chicken[x]));
		}
		result += min_dist;
	}

	return result;
}

void backtrack(int k, vector<int>& vec) {
	if (k == m) {
		// todo
		result = min(result, get_total_dist(vec));
		return;
	}
	for (int i = (k == 0) ? 0 : vec[k - 1]; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			vec.emplace_back(i);
			backtrack(k + 1, vec);
			visited[i] = false;
			vec.pop_back();
		}
	}
}

int main() {
	vector<int> vec;

	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;

			cin >> x;
			if (x == 1) {
				house.emplace_back(Point(i, j));
			} else if (x == 2) {
				chicken.emplace_back(Point(i, j));
			}
		}
	}

	backtrack(0, vec);

	cout << result << "\n";

	return 0;
}
