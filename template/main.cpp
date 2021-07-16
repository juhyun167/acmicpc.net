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

#define MAX		1000000

uint64_t m, n, t, k;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	map<int, int, greater<int>> map;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map.insert(1, 0);
	for (int i = 1; i < n; i++) {
		for (const auto el : map) {
			if (arr[el.second] < arr[i]) {
				map.insert(el.first + 1, i);
				break;
			}
		}
	}
	cout << map.begin()->first << "\n";
	return 0;
}

