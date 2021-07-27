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
#include <iomanip>
using namespace std;

#define MAX		500

uint64_t m, n, t, k, b;
int arr[MAX + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	map<int, int> mp;
	int __min = INT_MAX, __max = INT_MIN;
	
	setup();
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			__min = min(__min, arr[i][j]);
			__max = max(__max, arr[i][j]);
		}
	}

	for (int h = __min; h <= __max; h++) {
		int block = b, time = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] < h) {
					time += h - arr[i][j];
					block -= h - arr[i][j];
				} else {
					time += (arr[i][j] - h) * 2;
					block += arr[i][j] - h;
				}
			}
		}
		if (block >= 0) {
			map<int, int>::iterator iter = mp.find(time);
			
			if (iter == mp.end()) {
				mp[time] = h;
			} else {
				mp[time] = max(mp[time], h);
			}
		}
	}
	cout << mp.begin()->first << " " << mp.begin()->second << "\n";
	return 0;
}
