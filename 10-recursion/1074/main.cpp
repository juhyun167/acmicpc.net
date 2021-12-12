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

#define MAX		32768

uint64_t n, r, c;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int recursion(int k, int row, int col, int &cnt) {
	if (k == 0) {
		return cnt;
	}
	if (r < row + (1 << (k - 1))) {		
		if (c < col + (1 << (k - 1))) {
			return recursion(k - 1, row, col, cnt);
		} else {
			cnt += 1 << ((k - 1) << 1);
			return recursion(k - 1, row, col + (1 << (k - 1)), cnt);
		}
	} else {
		if (c < col + (1 << (k - 1))) {
			cnt += 2 << ((k - 1) << 1);
			return recursion(k - 1, row + (1 << (k - 1)), col, cnt);
		} else {
			cnt += 3 << ((k - 1) << 1);
			return recursion(k - 1, row + (1 << (k - 1)), col + (1 << (k - 1)), cnt);
		}
	}
}

int main() {
	int cnt = 0;

	setup();
	cin >> n >> r >> c;
	cout << recursion(n, 0, 0, cnt) << "\n";

	return 0;
}
