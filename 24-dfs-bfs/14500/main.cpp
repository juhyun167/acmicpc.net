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
#include <iomanip>
using namespace std;

#define MAX		(500 + 1)

int m, n, t, k, v;
int arr[MAX][MAX];
bool visited[MAX][MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool check(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

int search(int y, int x, int k) {
	int max = INT_MIN;
	const int dy[4] = { 0, 0, 1, -1 };
	const int dx[4] = { 1, -1, 0, 0 };

	if (k == 4) {
		return arr[y][x];
	}
	for (int i = 0; i < 4; i++) {
		int wy = y + dy[i];
		int wx = x + dx[i];
		int sum = 0;

		if (check(wy, wx) && !visited[wy][wx]) {
			visited[wy][wx] = true;
			sum = arr[y][x] + search(wy, wx, k + 1);
			max = (sum > max) ? sum : max;
			visited[wy][wx] = false;
		}
	}
	return max;
}

int search2(int y, int x) {
	int max = INT_MIN;
	const int d[4][4][2] = {
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
		{ { 0, 0 }, { 0, 1 }, { -1, 1 }, { 1, 1 } },
		{ { 0, 0 }, { 0, 1 }, { -1, 1 }, { 0, 2 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
	};

	for (int i = 0; i < 4; i++) {
		int sum = 0;
		bool valid = true;

		for (int j = 0; j < 4; j++) {
			int wy = y + d[i][j][0];
			int wx = x + d[i][j][1];

			if (check(wy, wx)) {
				sum += arr[wy][wx];
			} else {
				valid = false;
				break;
			}
		}
		max = (valid && sum > max) ? sum : max;
	}
	return max;
}

int main() {
	int maxres = INT_MIN;

	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			maxres = max({ maxres, search(i, j, 1),
							search2(i, j) });
			visited[i][j] = false;
		}
	}
	cout << maxres << "\n";

	return 0;
}
