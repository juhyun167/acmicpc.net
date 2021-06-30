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

void count(int n, int &cnt, int &cnt2) {
	while (n > 1) {
		if (n % 2 == 0) {
			cnt++;
			n /= 2;
		} else if (n % 5 == 0) {
			cnt2++;
			n /= 5;
		} else {
			break;
		}
	}
}

int main() {
	int cnt = 0, cnt2 = 0;

	setup();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		count(i, cnt, cnt2);
	}
	cout << min(cnt, cnt2) << "\n";
	return 0;
}
