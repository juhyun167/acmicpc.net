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
	setup();
	cin >> n;
	while (n > 1) {
		if (isPrime(n)) {
			cout << n << "\n";
			break;
		}
		for (int i = 2; i <= (int) sqrt(n); i++) {
			if (isPrime(i) && n % i == 0) {
				cout << i << "\n";
				n /= i;
				break;
			}
		}
	}
	return 0;
}
