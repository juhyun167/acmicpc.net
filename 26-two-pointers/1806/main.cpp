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

#define MAX		(100000 + 1)

int m, n, t, k, v, s;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int l = 1, r = 1, sum = 0;
	int result = INT_MAX;

	setup();
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	sum = arr[1];
	while (r - 1 <= n) {
		if (sum < s) {
			sum += arr[++r];
		} else {
			result = min(result, r - l + 1);
			if (l == r) {
				sum -= arr[l++];
				sum += arr[++r];
			} else {
				sum -= arr[l++];
			}
		}
	}
	if (result == INT_MAX) {
		result = 0;
	}
	cout << result << "\n";

	return 0;
}
