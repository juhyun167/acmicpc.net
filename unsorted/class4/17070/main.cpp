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

#define MAX		(16 + 1)

#define horizontal	(0)
#define vertical	(1)
#define diagonal	(2)

int m, n, t, k, v;
bool arr[MAX][MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

struct Pos {
	uint8_t y, x, type;

	Pos(uint8_t y, uint8_t x, uint8_t type) : y(y), x(x), type(type) {}
};

inline bool in_range_not_wall(uint8_t y, uint8_t x) {
	return 0 <= y && y < n && 0 <= x && x < n
				&& arr[y][x];
}

bool is_valid_pos(Pos *p) {
	uint8_t y = p->y, x = p->x;

	switch (p->type) {
		case horizontal:
			return in_range_not_wall(y, x)
						&& in_range_not_wall(y, x - 1);
		case vertical:
			return in_range_not_wall(y, x)
						&& in_range_not_wall(y - 1, x);
		case diagonal:
			return in_range_not_wall(y, x)
						&& in_range_not_wall(y, x - 1)
						&& in_range_not_wall(y - 1, x)
						&& in_range_not_wall(y - 1, x - 1);
		default:
			return false;
	}
}

int gen_neighbors(Pos *p, Pos **arr) {
	uint8_t y = p->y, x = p->x;

	switch (p->type) {
		case horizontal:
			arr[0] = new Pos(y, x + 1, horizontal);
			arr[1] = new Pos(y + 1, x + 1, diagonal);
			return 2;
		case vertical:
			arr[0] = new Pos(y + 1, x, vertical);
			arr[1] = new Pos(y + 1, x + 1, diagonal);
			return 2;
		case diagonal:
			arr[0] = new Pos(y, x + 1, horizontal);
			arr[1] = new Pos(y + 1, x, vertical);
			arr[2] = new Pos(y + 1, x + 1, diagonal);
			return 3;
		default:
			return 0;
	}
}

int search() {
	queue<Pos *> qu;
	int cnt = 0;

	if (!arr[n - 1][n - 1]) {
		return 0;
	}

	qu.push(new Pos(0, 1, horizontal));
	while (!qu.empty()) {
		Pos *u = qu.front();
		Pos *arr[3];
		int len;

		qu.pop();
		if (u->y == n - 1 && u->x == n - 1) {
			cnt++;
		} else {
			len = gen_neighbors(u, arr);
			for (int i = 0; i < len; i++) {
				if (is_valid_pos(arr[i])) {
					qu.push(arr[i]);
				}
			}
		}
		delete u;
	}

	return cnt;
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			
			cin >> x;
			arr[i][j] = (x == 0);
		}
	}

	cout << search() << "\n";

	return 0;
}
