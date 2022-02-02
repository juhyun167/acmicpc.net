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

#define MAX		(5000 + 1)

int m, n, t, k, v;
int64_t arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int64_t result = INT64_MAX;
	int64_t ans1, ans2, ans3;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(&arr[0], &arr[n]);

	for (int i = 0; i < n - 2; i++) {
		int64_t p = arr[i], temp_result = INT64_MAX;
		int l = i + 1, r = n - 1;
		int64_t temp_ans1, temp_ans2, temp_ans3;

		while (l < r) {
			if (abs(arr[l] + arr[r] + p) < temp_result) {
				temp_result = abs(arr[l] + arr[r] + p);
				temp_ans1 = arr[i], temp_ans2 = arr[l], temp_ans3 = arr[r];
			}
			if (arr[l] + arr[r] + p < 0) {
				l++;
			} else if (arr[l] + arr[r] + p > 0) {
				r--;
			} else {
				break;
			}
		}
		
		if (temp_result < result) {
			result = temp_result;
			ans1 = temp_ans1, ans2 = temp_ans2, ans3 = temp_ans3;
		}
	}

	cout << ans1 << " " << ans2 << " " << ans3 << "\n";

	return 0;
}
