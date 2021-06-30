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

int ncr(int n, int r) {
	vector<int> spf(n + 1);					// vector of SPFs
	unordered_map<int, int> prime_pow;		// map to store power of each prme
	int result = 1;

	r = (n - r > r) ? n - r : r;

	// initialize SPF vector
	for (int i = 0; i < n + 1; i++) {
		spf[i] = i;
	}

	// SPFs of even numbers are 2
	for (int i = 4; i < n + 1; i += 2) {
		spf[i] = 2;
	}

	// fill SPFs of odd numbers
	for (int i = 3; i < n + 1; i += 2) {
		if (i * i > n) {
			break;
		}
		// for primes, fill their multiples whose SPF is not set
		if (spf[i] == i) {
			for (int j = i * i; j < n + 1; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	/**
	 * Note that NCR = NC(N - R), so that NCR = (N - R + 1) * ... * N / R!
	 * = (R + 1) * ... * N / (N - R)!
	 */

	// for numerators we count frequencies of prime factors
	for (int i = r + 1; i < n + 1; i++) {
		int t = i;

		// recursive division for prime factorization
		while (t > 1) {
			if (prime_pow.find(spf[t]) == prime_pow.end()) {
				prime_pow[spf[t]] = 1;
			} else {
				prime_pow[spf[t]] += 1;
			}
			t /= spf[t];
		}
	}

	// for denominators we subtract the frequencies from the map
	for (int i = 1; i < n - r + 1; i++) {
		int t = i;

		while (t > 1) {
			prime_pow[spf[t]] -= 1;
			t /= spf[t];
		}
	}

	unordered_map<int, int>::iterator it;
	for (it = prime_pow.begin(); it != prime_pow.end(); it++) {
		result *= pow(it->first, it->second);
	}

	return result;
}

int main() {
	int t, k;

	setup();
	cin >> t;
	while (t--) {
		cin >> k >> n;
		cout << ncr(n, k) << "\n";
	}
	return 0;
}
