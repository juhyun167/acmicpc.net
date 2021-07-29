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

int main() {
	set<int> st;

	setup();

	// generate primes
	for (int i = 3; i < 1000000; i++) {
		bool prime = true;

		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				prime = false;
				break;
			}	
		}
		if (prime) {
			st.insert(i);
		}
	}

	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (const int &x : st) {
			if (st.find(n - x) != st.end()) {
				cout << n << " = " << x << " + " << n - x << "\n";
				break;
			}
		}
	}
	return 0;
}
