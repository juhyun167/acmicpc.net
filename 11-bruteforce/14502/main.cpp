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

#define MAX		(8 + 1)

int m, n, t, k, v;
int arr[MAX][MAX];
bool visited_virus[MAX][MAX];

vector<pair<int, int>> blank;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool in_range(int y, int x) {
	return 0 <= y && y < n && 0 <=x && x < m;
}

int bfs(int y, int x) {
	queue<pair<int, int>> qu;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	const int dy[4] = { 0, 0, 1, -1 };
	const int dx[4] = { 1, -1, 0, 0 };
	int cnt = 1;

	visited[y][x] = true;
	visited_virus[y][x] = true;
	qu.push(make_pair(y, x));
	while (!qu.empty()) {
		int uy, ux;

		tie(uy, ux) = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int wy = uy + dy[i], wx = ux + dx[i];
			
			if (arr[wy][wx] == 2) {
				visited_virus[wy][wx] = true;
			}
			if (in_range(wy, wx) && !visited[wy][wx]
					&& arr[wy][wx] != 1) {
				visited[wy][wx] = true;
				cnt++;
				qu.push(make_pair(wy, wx));
			}
		}
	}

	return cnt;
}

int search() {
	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2 && !visited_virus[i][j]) {
				result += bfs(i, j);
			}
		}
	}
	
	return n * m
			- (result + count(&arr[0][0], &arr[MAX - 1][MAX], 1));
}

void backtrack(vector<int>& vec, int k, int& result) {
	if (k == 3) {
		fill_n(&visited_virus[0][0], MAX * MAX, false);
		result = max(result, search());
		return;
	}
	for (int i = (k == 0) ? 0 : vec[k - 1] + 1; 
			i < blank.size(); i++) {
		int y = blank[i].first, x = blank[i].second;

		vec.emplace_back(i);
		arr[y][x] = 1;
		backtrack(vec, k + 1, result);
		arr[y][x] = 0;
		vec.pop_back();
	}
}

int main() {
	vector<int> vec;
	int result = INT_MIN;

	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				blank.emplace_back(make_pair(i, j));
			}
		}
	}
	backtrack(vec, 0, result);
	cout << result << "\n";

	return 0;
}
