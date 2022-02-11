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

#define MAX		(100 + 1)

#define inside	(0)
#define cheese	(1)
#define air		(2)

int m, n, t, k, v;
int arr1[MAX][MAX], arr2[MAX][MAX];
bool visited[MAX][MAX];

const int dy[4] = { 0, 0, 1, -1 };
const int dx[4] = { 1, -1, 0, 0 };

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool in_range(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

void mark_air() {
	queue<pair<int, int>> qu;

	// initialize
	fill_n(&visited[0][0], MAX * MAX, false);

	visited[0][0] = true;
	arr1[0][0] = arr2[0][0] = air;
	qu.push(make_pair(0, 0));
	while (!qu.empty()) {
		int y, x;

		tie(y, x) = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int wy = y + dy[i], wx = x + dx[i];

			if (in_range(wy, wx) && !visited[wy][wx]
					&& arr1[wy][wx] != cheese) {
				visited[wy][wx] = true;
				arr1[wy][wx] = arr2[wy][wx] = air;
				qu.push(make_pair(wy, wx));
			}
		}
	}
}

void dissolve() {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			int cnt = 0;

			if (arr2[i][j] != cheese) {
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k], x = j + dx[k];

				if (in_range(y, x) && arr1[y][x] == air) {
					cnt++;
				}
			}
			if (cnt >= 2) {
				arr2[i][j] = air;
			}
		}
	}
}

inline bool no_cheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr2[i][j] == cheese) {
				return false;
			}
		}
	}
	
	return true;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	int t = 0;

	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
			arr2[i][j] = arr1[i][j];
		}
	}

	do {
		mark_air();
		dissolve();
		t++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr1[i][j] = arr2[i][j];
			}
		}
	} while (!no_cheese());
	cout << t << "\n";

	return 0;
}
