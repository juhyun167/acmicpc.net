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

int generate(int n) {
	int sum = n;

	while (n > 0) {
		sum += n % 10;
		n = (n - n % 10) / 10;
	}
	return sum;
}

int main() {
	setup();
	cin >> n;

	for (int i = 1; i < n; i++) {
		if (generate(i) == n) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}
