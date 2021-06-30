#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		500000

unsigned long long m, n, t;
int arr[MAX + 1];
int cnt[MAX + 1];

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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i] + 4000] += 1;
	}
	sort(arr, arr + n);

	// 1. Average
	int avg = (int) round((double) accumulate(arr, arr + n, 0) / n);

	// 2. Median
	int median;

	if (n % 2 == 1) {
		median = arr[n / 2];
	} else {
		median = (arr[n / 2] + arr[n / 2 - 1]) / 2;
	}

	// 3. Mode
	vector<int> candidates;
	int mode, cntmax = *max_element(cnt, cnt + MAX + 1);

	for (int i = 0; i < MAX + 1; i++) {
		if (cnt[i] == cntmax) {
			candidates.emplace_back(i - 4000);
		}
	}
	sort(candidates.begin(), candidates.end());
	if (candidates.size() > 1) {
		mode = candidates[1];
	} else {
		mode = candidates[0];
	}

	// 4. Range
	int range = *max_element(arr, arr + n) - *min_element(arr, arr + n);

	cout << avg << "\n";
	cout << median << "\n";
	cout << mode << "\n";
	cout << range << "\n";
	return 0;
}
