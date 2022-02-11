#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;

#define MAX		9

unsigned long long m, n, t, cnt;
int world[MAX + 1][MAX + 1];
bool rowHas[MAX + 1][MAX + 1], colHas[MAX + 1][MAX + 1];
bool areaHas[MAX + 1][MAX + 1];
int blankPosY[MAX * MAX + 1], blankPosX[MAX * MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline int getArea(int y, int x) {
	return (y / 3) * 3 + (x / 3);
}

bool check(int y, int x, int n) {
	int area = getArea(y, x);

	if (rowHas[y][n] || colHas[x][n] || areaHas[area][n]) {
		return false;
	} else {
		return true;
	}
}

void backtrack(int k);

void backtrack(int k) {
	int y = blankPosY[k], x = blankPosX[k];
	int area = getArea(y, x);

	if (k == n) {
		cnt += 1;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (check(y, x, i)) {
			world[y][x] = i;
			rowHas[y][i] = colHas[x][i] = areaHas[area][i] = true;
			backtrack(k + 1);
			if (cnt > 0) {
				return;
			}
			rowHas[y][i] = colHas[x][i] = areaHas[area][i] = false;
		}
	}
}

int main() {
	setup();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int x;

			cin >> x;
			world[i][j] = x;
			if (x > 0) {
				rowHas[i][x] = colHas[j][x] = true;
				areaHas[getArea(i, j)][x] = true;
			} else {
				blankPosY[n] = i, blankPosX[n] = j;
				n += 1;
			}
		}
	}
	backtrack(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << world[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
