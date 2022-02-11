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
unsigned long long d[MAX + 1], price[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	unsigned long long res = 0, minPrice = ULLONG_MAX;

	setup();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	for (int i = 0; i < n - 1; i++) {
		minPrice = (price[i] < minPrice) ? price[i] : minPrice;
		res += minPrice * d[i];
	}
	cout << res << "\n";
	return 0;
}
