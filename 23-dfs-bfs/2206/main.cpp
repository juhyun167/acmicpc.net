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

#define MAX		(1000 + 1)
#define INF		(INT_MAX)

int m, n, t, k, v;
char arr[MAX][MAX];
bool visited[MAX][MAX][2];	// y, x, breaking counts
int d[MAX][MAX][2];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool check(int y, int x) {
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

int bfs() {
	queue<tuple<int, int, bool>> qu;
	const int dy[4] = { 0, 0, -1, 1 };
	const int dx[4] = { 1, -1, 0, 0 };

	fill_n(&d[0][0][0], MAX * MAX * 2, INF);

	visited[1][1][0] = true;
	d[1][1][0] = 1;
	qu.push(make_tuple(1, 1, true));
	while (!qu.empty()) {
		int y, x, breakable;

		tie(y, x, breakable) = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int uy = y + dy[i], ux = x + dx[i];

			if (!check(uy, ux)) {
				continue;
			}
			if (breakable && arr[uy][ux] == '1' &&
					!visited[uy][ux][1]) {
				// breakable wall
				visited[uy][ux][1] = true;
				d[uy][ux][1] = d[y][x][0] + 1;
				qu.push(make_tuple(uy, ux, false));
			} else if (breakable && arr[uy][ux] == '0' &&
					!visited[uy][ux][0]) {
				visited[uy][ux][0] = true;
				d[uy][ux][0] = d[y][x][0] + 1;
				qu.push(make_tuple(uy, ux, true));
			} else if (!breakable && arr[uy][ux] == '0' &&
					!visited[uy][ux][1]) {
				visited[uy][ux][1] = true;
				d[uy][ux][1] = d[y][x][1] + 1;
				qu.push(make_tuple(uy, ux, false));
			}
		}
	}

	return min(d[n][m][0], d[n][m][1]);
}

int main() {
	int result;

	setup();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	result = bfs();
	if (result == INF) {
		cout << "-1\n";
	} else {
		cout << result << "\n";
	}

	return 0;
}