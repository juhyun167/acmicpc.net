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

#define MAX		(100 + 1)

uint64_t m, n, t, k, v;
int arr[MAX][MAX], d[MAX][MAX];
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

int bfs(int vy, int vx) {
	queue<int> qy, qx;
	int uy, ux, wy, wx;
	const int dy[4] = { 0, 0, 1, -1 };
	const int dx[4] = { 1, -1, 0, 0 };

	qy.push(vy);
	qx.push(vx);
	while (!qy.empty()) {
		uy = qy.front();
		ux = qx.front();

		qy.pop();
		qx.pop();
		if (uy == n - 1 && ux == m - 1) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			wy = uy + dy[i];
			wx = ux + dx[i];

			if (check(wy, wx) && !visited[wy][wx]
					&& arr[wy][wx] == 1) {
				visited[wy][wx] = true;
				d[wy][wx] = d[uy][ux] + 1;
				qy.push(wy);
				qx.push(wx);
			}
		}
	}
	
	return d[uy][ux] + 1;
}

int main() {
	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	cout << bfs(0, 0) << "\n";

	return 0;
}
