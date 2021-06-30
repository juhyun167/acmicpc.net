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
bool arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool isPrime(int n) {
	if (arr[n]) {
		return true;
	}
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i = 2; i <= (int) sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	arr[n] = true;
	return true;
}

int countPrime(int first, int last) {
	int cnt = 0;

	for (int i = first; i <= last; i++) {
		if (isPrime(i)) {
			cnt += 1;
		}	
	}
	return cnt;
}

int main() {
	setup();
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << countPrime(n + 1, 2 * n) << "\n";
	}
	return 0;
}
