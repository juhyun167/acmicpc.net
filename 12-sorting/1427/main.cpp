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

#define MAX		1000000

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	vector<int> v;

	setup();
	cin >> n;
	while (n > 0) {
		int x = n % 10;

		v.emplace_back(x);
		n = (n - x) / 10;
	}
	sort(v.begin(), v.end(), greater<>());
	for (auto it = v.begin(); it != v.end(); it++) {
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}
