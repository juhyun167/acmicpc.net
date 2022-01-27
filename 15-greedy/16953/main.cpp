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
#include <list>
#include <utility>
#include <iomanip>
using namespace std;

#define MAX		(1000000000 + 1)

int m, n, t, k, v;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int a, b, cnt = 1;

	setup();
	cin >> a >> b;
	while (b > 0) {
		if (b == a) {
			break;
		}
		if (b % 10 == 1) {
			b /= 10;
		} else if (!(b & 1)) {
			b /= 2;
		} else {
			cnt = -1;
			break;
		}
		cnt++;
	}
	if (b <= 0) {
		cnt = -1;
	}
	cout << cnt << "\n";

	return 0;
}
