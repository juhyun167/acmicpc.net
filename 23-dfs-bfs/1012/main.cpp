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

#define MAX		50

uint64_t m, n, t, k, v;
bool arr[MAX][MAX], visited[MAX][MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool check(int y, int x) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

void bfs(int y, int x) {
	queue<tuple<int, int>> qu;
	const int dy[4] = { 0, 0, 1, -1 };
	const int dx[4] = { 1, -1, 0, 0 };

	qu.push(make_tuple(y, x));
	while (!qu.empty()) {
		int uy, ux;

		tie(uy, ux) = qu.front();
		qu.pop();
		if (!visited[uy][ux]) {
			visited[uy][ux] = true;
			for (int i = 0; i < 4; i++) {
				int wy = uy + dy[i];
				int wx = ux + dx[i];

				if (check(wy, wx) && arr[wy][wx]) {
					qu.push(make_tuple(wy, wx));
				}
			}
		}
	}
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		int cnt = 0;

		cin >> m >> n >> k;

		fill_n(&arr[0][0], MAX * MAX, false);
		fill_n(&visited[0][0], MAX * MAX, false);

		while (k--) {
			int x, y;

			cin >> x >> y;
			arr[y][x] = true;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}
