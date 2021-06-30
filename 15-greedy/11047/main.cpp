#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iomanip>
using namespace std;

#define MAX		10

unsigned long long m, n, t, k;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int cnt = 0;

	setup();
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; k > 0 && i >= 0; i--) {
		if (k / arr[i] == 0) {
			continue;
		}
		int x =  k / arr[i];
		cnt += x;
		k -= x * arr[i];
	}
	cout << cnt << "\n";
	return 0;
}
