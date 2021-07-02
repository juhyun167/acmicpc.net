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
#include <stack>
#include <queue>
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

unsigned long long modpow(unsigned long long base, 
			unsigned long long exp, unsigned long long modulus) {
	unsigned long long result = 1;

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
	unsigned long long a, b, c;

	setup();
	cin >> a >> b >> c;
	cout << modpow(a, b, c) << "\n";
	return 0;
}
