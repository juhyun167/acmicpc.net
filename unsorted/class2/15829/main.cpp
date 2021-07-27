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
#include <iomanip>
using namespace std;

#define MAX		1000000

uint64_t m, n, t, k;
int arr[MAX + 1];

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
	string s;
	uint64_t res = 0;

	setup();
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++) {
		res += modpow(31, i, 1234567891) * (s[i] - 'a' + 1);
		res %= 1234567891;
	}
	cout << res << "\n";
	return 0;
}
