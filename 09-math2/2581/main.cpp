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
	vector<int> v;

	setup();
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (isPrime(i)) {
			v.emplace_back(i);
		}
	}
	if (v.size() != 0) {
		cout << accumulate(v.begin(), v.end(), 0) << "\n";
		cout << *min_element(v.begin(), v.end()) << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
