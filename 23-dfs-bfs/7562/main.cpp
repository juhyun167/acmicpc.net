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

#define MAX		(300 + 1)

uint64_t m, n, t, k, v;
int d[MAX][MAX];
bool visited[MAX][MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool check(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

int search(int vy, int vx, int dsy, int dsx) {
	queue<int> qy, qx;
	const int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	visited[vy][vx] = true;
	qy.push(vy);
	qx.push(vx);
	while (!qy.empty()) {
		int uy = qy.front(), ux = qx.front();
		
		qy.pop();
		qx.pop();

		if (uy == dsy && ux == dsx) {
			return d[uy][ux];
		}

		for (int i = 0; i < 8; i++) {
			int wy = uy + dy[i], wx = ux + dx[i];
			
			if (check(wy, wx) && !visited[wy][wx]) {
				visited[wy][wx] = true;
				d[wy][wx] = d[uy][ux] + 1;
				qy.push(wy);
				qx.push(wx);
			}
		}
	}

	return -1;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		int vy, vx, dsy, dsx;

		cin >> n;
		cin >> vy >> vx;
		cin >> dsy >> dsx;

		fill_n(&d[0][0], MAX * MAX, 0);
		fill_n(&visited[0][0], MAX * MAX, false);
		cout << search(vy, vx, dsy, dsx) << "\n";
	}

	return 0;
}
