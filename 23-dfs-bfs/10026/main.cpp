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
int arr[MAX][MAX];
bool visited[MAX][MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool check(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

void search(int y, int x) {
	const int dy[4] = { 0, 0, -1, 1 };
	const int dx[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++) {
		int wy = y + dy[i], wx = x + dx[i];

		if (check(wy, wx) && !visited[wy][wx]
				&& arr[wy][wx] == arr[y][x]) {
			visited[wy][wx] = true;
			search(wy, wx);
		}
	}
}

int main() {
	int cnt = 0, cnt2 = 0;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - 'A';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				search(i, j);
				cnt++;
			}
		}
	}
	fill_n(&visited[0][0], MAX * MAX, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = (arr[i][j] == 'G' - 'A') ?
							'R' - 'A' : arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				search(i, j);
				cnt2++;
			}
		}
	}
	cout << cnt << " " << cnt2 << "\n";

	return 0;
}
