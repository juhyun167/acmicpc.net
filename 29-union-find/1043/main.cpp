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

int m, n, t, k, v;
int arr[MAX][MAX], len[MAX];
int truth[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

template <typename T>
class disjoint_set {
	unordered_map<T, T> parent;
	unordered_map<T, int> rank;

	void link(T x, T y) {
		if (rank[x] > rank[y]) {
			parent[y] = x;
		} else {
			parent[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
	}

public:
	void make_set(T x) {
		if (parent.count(x) == 0) {
			parent[x] = x;
			rank[x] = 0;
		}
	}

	void union_set(T x, T y) {
		link(find_set(x), find_set(y));
	}

	T find_set(T x) {
		if (x != parent[x]) {
			parent[x] = find_set(parent[x]);
		}
		
		return parent[x];
	}
};

int main() {
	disjoint_set<int> ds;
	int cnt = 0;

	setup();
	cin >> n >> m;
	cin >> k;
	if (k == 0) {
		cout << m << "\n";
		return 0;
	}
	for (int i = 0; i < k; i++) {
		cin >> truth[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> len[i];
		cin >> arr[i][0];
		ds.make_set(arr[i][0]);
		for (int j = 1; j < len[i]; j++) {
			cin >> arr[i][j];
			ds.make_set(arr[i][j]);
			ds.union_set(arr[i][0], arr[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		bool result = true;

		for (int j = 0; j < k; j++) {
			if (ds.find_set(arr[i][0]) == ds.find_set(truth[j])) {
				result = false;
				break;
			}
		}
		if (result) {
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}
