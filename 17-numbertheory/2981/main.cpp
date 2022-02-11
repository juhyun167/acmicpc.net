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

void count(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			cout << i << " ";
		}
	}
	cout << n << "\n";
}

int main() {
	int d;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr[n] = arr[n - 1];
	d = gcd(abs(arr[0] - arr[1]), abs(arr[1] - arr[2]));
	for (int i = 1; i < n; i++) {
		d = gcd(d, abs(arr[i] - arr[i + 1]));
	}
	count(d);
	return 0;
}
