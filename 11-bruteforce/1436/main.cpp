#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
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

bool test(int n) {
	string s = to_string(n);

	if (s.find("666") != string::npos) {
		return true;
	}
	return false;
}

int main() {
	int x = 666, cnt = 0;

	setup();
	cin >> n;
	while (true) {
		if (test(x)) {
			cnt += 1;
		}
		if (cnt == n) {
			break;
		}
		x += 1;
	}
	cout << x << "\n";
	return 0;
}
