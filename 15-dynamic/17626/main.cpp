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

#define MAX		(50000 + 1)

uint64_t m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> n;

	for (int i = 1; i * i <= MAX; i++) {
		arr[i * i] = 1;
	}

	if (arr[n] == 1) {
		cout << "1\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int min = INT_MAX;

		if (arr[i] == 1) {
			continue;
		}
		for (int j = 1; j <= i / 2; j++) {
			min = (arr[j] + arr[i - j] < min) ?
					arr[j] + arr[i - j] : min;
			if (min == 2) {
				break;
			}
		}
		arr[i] = min;
	}
	cout << arr[n] << "\n";

	return 0;
}
