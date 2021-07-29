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
uint64_t arr[MAX + 1] = { 0, 1, 2, 4 };

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		cin >> n;
		if (arr[n] == 0) {
			for (int i = 4; i <= n; i++) {
				arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])
							% 1000000009;
			}
		}
		cout << arr[n] << "\n";
	}
	return 0;
}
