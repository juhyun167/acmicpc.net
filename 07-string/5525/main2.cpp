#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
using namespace std;

#define MAX		(1000000 + 1)

uint64_t m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

uint64_t modpow(uint64_t base, uint64_t exp, uint64_t modulus) {
	uint64_t result = 1;

	base %= modulus;
	while (exp > 0) {
		if (exp & 1) {
			result = (result * base) % modulus;
		}
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result % modulus;
}

int main() {
	string s, pattern = "";
	uint64_t d = 2, q = 1000000007, h, p = 0;
	int cnt = 0;

	setup();
	cin >> n >> m >> s;

	// preprocessing
	for (int i = 0; i < s.length(); i++) {
		s[i] = (s[i] == 'I') ? '1' : '0';
	}
	for (int i = 0; i < n * 2 + 1; i++) {
		pattern = !(i & 1) ? pattern + "1" : pattern + "0";
	}

	h = modpow(d, n * 2, q);
	for (int i = 0; i < n * 2 + 1; i++) {
		p = (d * p + (pattern[i] - '0')) % q;
		t = (d * t + (s[i] - '0')) % q;
	}

	// matching
	for (int i = 0; i < m - n * 2; i++) {
		if (p == t) {
			if (s.substr(i, n * 2 + 1) == pattern) {
				cnt++;
			}
		}
		t = (d * (t - (s[i] - '0') * h)
				+ (s[i + (n * 2 + 1)] - '0')) % q;
	}
	cout << cnt << "\n";

	return 0;
}
