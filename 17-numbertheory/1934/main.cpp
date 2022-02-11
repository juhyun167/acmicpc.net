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
	setup();
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;

		cin >> x >> y;
		int _gcd = gcd(x, y);
		int q1 = x / _gcd, q2 = y / _gcd;
		cout << _gcd * q1 * q2 << "\n";
	}
	return 0;
}
