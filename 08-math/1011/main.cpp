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

unsigned long long n, t;
int arr[MAX + 1];

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

	for (int i = 0; i < t; i++) {
		int x, y, d, k;

		cin >> x >> y;
		d = y - x;
		k = (int) floor(sqrt((double) d - 0.5));
		if ((k + 1) * (k + 1) - d >= k + 1) {
			cout << 2 * k << "\n";
		} else {
			cout << 2 * k + 1 << "\n";
		}
	}
	return 0;
}