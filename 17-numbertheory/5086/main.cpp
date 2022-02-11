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

int main() {
	int x, y;

	setup();
	while (true) {
		cin >> x >> y;
		if (x == 0 && y == 0) {
			break;
		}
		if (y % x == 0) {
			cout << "factor\n";
		} else if (x % y == 0) {
			cout << "multiple\n";
		} else {
			cout << "neither\n";
		}
	}
	return 0;
}
