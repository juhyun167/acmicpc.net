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

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
	fill_n(arr, MAX + 1, -1);
}

bool isPrime(int n) {
	if (arr[n] >= 0) {
		return (bool) arr[n];
	}
	for (int i = 2; i <= (int) sqrt(n); i++) {
		if (n % i == 0) {
			arr[n] = 0;
			return false;
		}
	}
	arr[n] = 1;
	return true;
}

void findPair(int n) {
	int max = 0;

	for (int i = 2; i <= n / 2; i++) {
		if (isPrime(i) && isPrime(n - i)) {
			max = (i > max) ? i : max;
		}
	}
	cout << max << " " << n - max << "\n";
}

int main() {
	setup();
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		findPair(n);
	}
	return 0;
}
