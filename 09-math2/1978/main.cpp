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

bool isPrime(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i = 2; i <= (int) sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int cnt = 0;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;
		if (isPrime(x)) {
			cnt += 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}
