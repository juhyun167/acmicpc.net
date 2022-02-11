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

#define MAX		(9 + 1)

int m, n, t, k, v;
int arr[MAX][MAX];
bool has_n_in_row[MAX][MAX];		// [row, n]
bool has_n_in_col[MAX][MAX];		// [col, n]
bool has_n_in_area[MAX][MAX];		// [area, n]
vector<pair<int, int>> blanks;		// [row, col]

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

/**
 * area is as follows.
 *
 *     (1~3)(4~6)(7~9)
 * (1~3) 1    2    3
 * (4~6) 4    5    6
 * (7~9) 7    8    9
 */
inline int get_area(int r, int c) {
	return (r - 1) / 3 * 3 + (c - 1) / 3 + 1;
}

bool placeable_here(int r, int c, int n) {
	int a = get_area(r, c);

	return !(has_n_in_row[r][n] || has_n_in_col[c][n]
				|| has_n_in_area[a][n]);
}

void place(int r, int c, int n) {
	int a = get_area(r, c);

	arr[r][c] = n;
	has_n_in_row[r][n] = true;
	has_n_in_col[c][n] = true;
	has_n_in_area[a][n] = true;
}

void remove(int r, int c, int n) {
	int a = get_area(r, c);

	arr[r][c] = 0;
	has_n_in_row[r][n] = false;
	has_n_in_col[c][n] = false;
	has_n_in_area[a][n] = false;
}

bool solve(int k) {
	int r, c;
	int result;

	if (k == blanks.size()) {
		return true;
	}
	tie(r, c) = blanks[k];
	for (int n = 1; n <= 9; n++) {
		if (placeable_here(r, c, n)) {
			place(r, c, n);
			result = solve(k + 1);
			if (result) {
				return true;
			}
			remove(r, c, n);
		}
	}

	return false;
}

int main() {
	setup();
	for (int i = 1; i <= 9; i++) {
		string s;

		cin >> s;
		for (int j = 1; j <= 9; j++) {
			int x = (char) s[j - 1] - '0';
			int a = get_area(i, j);

			arr[i][j] = x;
			if (x != 0) {
				has_n_in_row[i][x] = true;
				has_n_in_col[j][x] = true;
				has_n_in_area[a][x] = true;
			} else {
				blanks.emplace_back(make_pair(i, j));
			}
		}
	}

	solve(0);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}
