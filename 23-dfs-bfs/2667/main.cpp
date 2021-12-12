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

#define MAX		(25 + 1)

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

inline bool check(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

int bfs(int uy, int ux) {
	int cnt = 1;
	const int dy[4] = { 0, 0, -1, 1 };
	const int dx[4] = { 1, -1, 0, 0 };

	visited[uy][ux] = true;
	for (int i = 0; i < 4; i++) {
		int wy = uy + dy[i];
		int wx = ux + dx[i];

		if (check(wy, wx) && !visited[wy][wx]
				&& arr[wy][wx] == 1) {
			visited[wy][wx] = true;
			cnt += bfs(wy, wx);
		}
	}

	return cnt;
}

int main() {
	vector<int> vec;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				vec.emplace_back(bfs(i, j));
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";
	for (const int &x : vec) {
		cout << x << "\n";
	}

	return 0;
}
