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

int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	setup();
	cin >> n;
	cout << fibonacci(n) << "\n";
	return 0;
}
