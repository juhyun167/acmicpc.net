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

static inline void ltrim(string &s) {
	s.erase(s.begin(), find_if(
		s.begin(), s.end(), [](unsigned char ch) {
			return !isspace(ch);
		}
	));
}

int main() {
	string a, b, c;
	int lenA, lenB;
	bool carry = false;

	setup();
	cin >> a >> b;
	lenA = a.length();
	lenB = b.length();
	n = max(lenA, lenB);
	if (lenA < n) {
		for (int i = 0; i < n - lenA; i++) {
			a = '0' + a;
		}
	} else if (lenB < n) {
		for (int i = 0; i < n - lenB; i++) {
			b = '0' + b;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (carry) {
			carry = ((a[i] - '0') + (b[i] - '0') + 1) / 10 > 0;
			c = (char) (((a[i] - '0') + (b[i] - '0') + 1) % 10 + '0') + c;
		} else {
			carry = ((a[i] - '0') + (b[i] - '0')) / 10 > 0;
			c = (char) (((a[i] - '0') + (b[i] - '0')) % 10 + '0') + c;
		}
	}
	if (carry) {
		c = '1' + c;
	}
	cout << c << "\n";
	return 0;
}
