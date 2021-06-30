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

int count(unsigned long long n, int x) {
	int cnt = 0;

	if (n == 0) {
		return 0;
	}
	for (unsigned long long i = x; n / i >= 1; i *= x) {
		cnt += n / i;
	}
	return cnt;
}

int main() {
	int res2, res5;

	setup();
	cin >> n >> m;
	res2 = count(n, 2) - (count(m, 2) + count(n - m, 2));
	res5 = count(n, 5) - (count(m, 5) + count(n - m, 5));
	cout << min(res2, res5) << "\n";
	return 0;
}
