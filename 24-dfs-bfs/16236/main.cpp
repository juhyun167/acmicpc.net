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

#define MAX		(20 + 1)

uint64_t m, n, t, k, v;
int arr[MAX][MAX], d[MAX][MAX];
bool visited[MAX][MAX];
int sz = 2, eaten = 0;

struct Pos {
	int y, x;
	
	Pos(int y, int x) : y(y), x(x) {}

	bool operator<(const Pos &other) const {
		if (d[y][x] == d[other.y][other.x]) {
			return (y == other.y) ? x > other.x : y > other.y;
		}
		return d[y][x] > d[other.y][other.x];
	}
};

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

bool search(int &vy, int &vx, int &time) {
	priority_queue<Pos> pq;
	int uy, ux, wy, wx;
	const int dy[4] = { 0, 0, 1, -1 };
	const int dx[4] = { 1, -1, 0, 0 };

	fill_n(&d[0][0], MAX * MAX, 0);
	fill_n(&visited[0][0], MAX * MAX, false);

	pq.push(Pos(vy, vx));
	while (!pq.empty()) {
		uy = pq.top().y, ux = pq.top().x;

		pq.pop();
		if (arr[uy][ux] != 0 && arr[uy][ux] < sz) {
			// edible 
			arr[uy][ux] = 0;
			if (++eaten >= sz) {
				eaten = 0;
				sz++;
			}
			vy = uy, vx = ux;
			time += d[uy][ux];
			return true;
		}

		for (int i = 0; i < 4; i++) {
			wy = uy + dy[i], wx = ux + dx[i];

			if (check(wy, wx) && !visited[wy][wx]
					&& arr[wy][wx] <= sz) {
				// eligible for next vertice
				visited[wy][wx] = true;
				d[wy][wx] = d[uy][ux] + 1;
				pq.push(Pos(wy, wx));
			}
		}
	}
	// nothing to eat
	return false;
}

int main() {
	int vy, vx, time = 0;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				vy = i, vx = j;
				arr[i][j] = 0;
			}
		}
	}

	while (true) {
		if (!search(vy, vx, time)) {
			break;
		}
	}
	cout << time << "\n";

	return 0;
}
