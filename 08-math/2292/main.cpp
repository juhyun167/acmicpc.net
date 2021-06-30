#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	unsigned long long n, k;

	setup();
	cin >> n;

	k = (unsigned long long) ceil(sqrt((double) 2 * n + 0.25) + 0.5);
	if (k % 2 == 1) {
		printf("%llu/", k - ((k * (k - 1) / 2) - n + 1));
		printf("%llu\n", (k * (k - 1) / 2) - n + 1);
	} else {
		printf("%llu/", (k * (k - 1) / 2) - n + 1);
		printf("%llu\n", k - ((k * (k - 1) / 2) - n + 1));
	}
	return 0;
}
