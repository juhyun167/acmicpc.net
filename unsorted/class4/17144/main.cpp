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

#define MAX		(50 + 1)

int r, c, t, k, v;
int arr1[MAX][MAX], arr2[MAX][MAX];
int (*p1)[MAX] = arr1, (*p2)[MAX] = arr2;
int cr1, cr2;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool diffusable_pos(int y, int x) {
	return 0 <= y && y < r && 0 <= x && x <	c
				&& arr1[y][x] != -1;
}

void diffuse(int y, int x) {
	int d = p1[y][x] / 5, cnt = 0;
	const int dy[4] = { 0, 0, -1, 1 };
	const int dx[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++) {
		int wy = y + dy[i], wx = x + dx[i];

		if (diffusable_pos(wy, wx)) {
			p2[wy][wx] += d;
			p2[y][x] -= d;
			cnt++;
		}
	}
	if (p2[y][x] < 0) {
		p2[y][x] = 0;
	}
}

void do_diffuse() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			p2[i][j] = p1[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (p1[i][j] != -1) {
				diffuse(i, j);
			}
		}
	}
	swap(p1, p2);
}

void upper_clean() {
	for (int i = cr1 - 1; i > 0; i--) {
		p1[i][0] = p1[i - 1][0];
	}
	for (int j = 0; j < c - 1; j++) {
		p1[0][j] = p1[0][j + 1];
	}
	for (int i = 0; i < cr1; i++) {
		p1[i][c - 1] = p1[i + 1][c - 1];
	}
	for (int j = c - 1; j > 1; j--) {
		p1[cr1][j] = p1[cr1][j - 1];
	}
	p1[cr1][1] = 0;
}

void lower_clean() {
	for (int i = cr2 + 1; i < r - 1; i++) {
		p1[i][0] = p1[i + 1][0];
	}
	for (int j = 0; j < c - 1; j++) {
		p1[r - 1][j] = p1[r - 1][j + 1];
	}
	for (int i = r - 1; i > cr2; i--) {
		p1[i][c - 1] = p1[i - 1][c - 1];
	}
	for (int j = c - 1; j > 1; j--) {
		p1[cr2][j] = p1[cr2][j - 1];
	}
	p1[cr2][1] = 0;
}

void do_clean() {
	upper_clean();
	lower_clean();
}

int main() {
	int result = 0;

	setup();
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr1[i][j];
			arr2[i][j] = arr1[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		if (arr1[i][0] == -1) {
			cr1 = i;
			cr2 = i + 1;
			break;
		}
	}

	while (t--) {
		do_diffuse();
		do_clean();
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result += p1[i][j];
		}
	}
	result += 2;
	cout << result << "\n";

	return 0;
}
